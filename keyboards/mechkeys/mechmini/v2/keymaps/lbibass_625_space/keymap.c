#include QMK_KEYBOARD_H

#define _BL 0
#define _FN1 2
#define _FN2 3
#define _WIN 1
#define _FN3 4
//Tap Dance Declarations
enum
{
  TD_DOTCOM = 0
};
//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
    //Tap once for Esc, twice for Caps Lock
    [TD_DOTCOM] = ACTION_TAP_DANCE_DOUBLE(KC_COMMA, KC_DOT)
    // Other declarations would go here, separated by commas, if you have them
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BL] = LAYOUT_625_space(
        LT(OSL(2), KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        GUI_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(3, KC_ENT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, TD(TD_DOTCOM), OSL(2), OSM(MOD_RSFT),
        KC_ESC, KC_LALT, KC_LCTL, KC_SPC, KC_RGUI, MO(4)),
    [_WIN] = LAYOUT_625_space(
        LT(OSL(2), KC_TAB), KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC,
        CTL_T(KC_ESC), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(4, KC_ENT),
        KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, TD(TD_DOTCOM), OSL(2), OSM(MOD_RSFT),
        KC_ESC, KC_LGUI, KC_LALT, KC_SPC, KC_RALT, RGB_TOG),
    [_FN1] = LAYOUT_625_space(
        KC_GRV, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC,
        GUI_T(KC_ESC), KC_PGUP, KC_VOLU, KC_DEL, KC_TRNS, KC_BSLS, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL, KC_TRNS,
        KC_LSFT, KC_PGDN, KC_VOLD, BL_STEP, BL_TOGG, KC_SCLN, KC_QUOT, KC_SLSH, KC_DOT, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN2] = LAYOUT_625_space(
        KC_PWR, KC_BRID, KC_BRIU, KC_NO, KC_NO, KC_NO, KC_NO, KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, QK_BOOT,
        MT(KC_LGUI, KC_ESC), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TG(1), KC_TRNS, KC_TRNS, KC_VOLD, KC_VOLU, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

    [_FN3] = LAYOUT_625_space(
        KC_PWR, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, QK_BOOT,
        MT(KC_LGUI, KC_ESC), KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, TG(1), KC_TRNS, KC_TRNS, KC_F11, KC_F12, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_VAI, RGB_VAD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, KC_TRNS, KC_TRNS,
        KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)

};
