// Copyright 2023 Florent Linguenheld (@FLinguenheld)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keycodes.h"

/* Only for basis letters
   Exceptions like Tab or Enter */
bool get_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {

    switch (keycode) {

        case KC_TAB:
        case KC_ENT:

        // --
        case KC_A:
        case KC_B:
        case KC_C:
        case KC_D:
        case KC_E:
        case KC_F:
        case KC_G:
        case KC_H:
        case KC_I:
        case KC_J:
        case KC_K:
        case KC_L:
        case KC_M:
        case KC_N:
        case KC_O:
        case KC_P:
        case KC_Q:
        case KC_R:
        case KC_S:
        case KC_T:
        case KC_U:
        case KC_V:
        case KC_W:
        case KC_X:
        case KC_Y:
        case KC_Z:

            return true;
    }

    return get_custom_auto_shifted_key(keycode, record);
}


/* Custom auto shift
   I use this instead of tap dance because double tap is horrible
   Add here the letter or the custom enum, then add in press_user and press_release the actions */
bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:
        case KC_LABK:  // Easy indent with vim
        case KC_RABK:

        /* French */
        case CS_E_ACUTE:

        case CS_A_GRAVE:
        case CS_E_GRAVE:
        case CS_I_GRAVE:
        case CS_O_GRAVE:
        case CS_U_GRAVE:

        case CS_A_CIRCUMFLEX:
        case CS_E_CIRCUMFLEX:
        case CS_I_CIRCUMFLEX:
        case CS_O_CIRCUMFLEX:
        case CS_U_CIRCUMFLEX:

        case CS_A_DIAERESIS:
        case CS_E_DIAERESIS:
        case CS_I_DIAERESIS:
        case CS_O_DIAERESIS:
        case CS_U_DIAERESIS:
        case CS_Y_DIAERESIS:

        case CS_C_CEDILLA:
        case CS_AE:
        case CS_OE:

            return true;

        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:
            register_code16((!shifted) ? KC_BSPC : KC_DEL);
            break;

        case KC_LABK:
            if (shifted) { send_unicode_string("<<"); }
            else         { send_unicode_string("<"); } break;

        case KC_RABK:
            if (shifted) { send_unicode_string(">>"); }
            else         { send_unicode_string(">"); } break;

        /* French
           Release is not necessary with 'send_unicode_string()' */
        case CS_E_ACUTE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;

        case CS_A_GRAVE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_E_GRAVE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_I_GRAVE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_O_GRAVE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_U_GRAVE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;

        case CS_A_CIRCUMFLEX:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_E_CIRCUMFLEX:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_I_CIRCUMFLEX:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_O_CIRCUMFLEX:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_U_CIRCUMFLEX:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;

        case CS_A_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_E_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_I_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_O_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_U_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;
        case CS_Y_DIAERESIS:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); }  break;

        case CS_C_CEDILLA:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_AE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;
        case CS_OE:
            if (shifted) { send_unicode_string("??"); }
            else         { send_unicode_string("??"); } break;


        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            /* & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift */
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch(keycode) {

        case KC_BSPC:
            unregister_code16((!shifted) ? KC_BSPC : KC_DEL);
            break;

        default:
            /* & 0xFF gets the Tap key for Tap Holds, required when using Retro Shift
               The IS_RETRO check isn't really necessary here, always using
               keycode & 0xFF would be fine. */
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
