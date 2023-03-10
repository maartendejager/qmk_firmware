#include QMK_KEYBOARD_H

// Compile from qmk_firmware folder with the following command:
// $ make kbdfans/kbd67/mkii-soldered:adamdehaven

// Each layer gets a name for readability. The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, and you can also skip them entirely and just use numbers.
#define _QWERTY 0
#define _FN1 1

// Tap Dance Definitions
enum tapdance {
    TD_HOME = 0,
    TD_END
};

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Home, twice for PageUp
    [TD_HOME] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_PGUP),
    // Tap once for End, twice for PageDown
    [TD_END] = ACTION_TAP_DANCE_DOUBLE(KC_END, KC_PGDN)
};

/*
 *  You can use _______ in place for KC_TRNS (transparent)
 *  Or you can use XXXXXXX for KC_NO (NOOP)
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* 0: _QWERTY
     * ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┐
     * │ QK_GESC │ KC_1    │ KC_2    │ KC_3    │ KC_4    │ KC_5    │ KC_6    │ KC_7    │ KC_8    │ KC_9    │ KC_0    │ KC_MINS │ KC_EQL  │    KC_BSPC (2)    │ KC_DEL  │
     * ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤
     * │   KC_TAB     │ KC_Q    │ KC_W    │ KC_E    │ KC_R    │ KC_T    │ KC_Y    │ KC_U    │ KC_I    │ KC_O    │ KC_P    │ KC_LBRC │ KC_RBRC │   KC_BSLS    │ TD_HOME │
     * ├──────────────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴──────────────┼─────────┤
     * │    KC_CAPS     │ KC_A    │ KC_S    │ KC_D    │ KC_F    │ KC_G    │ KC_H    │ KC_J    │ KC_K    │ KC_L    │ KC_SCLN │ KC_QUOT │       KC_ENT         │ TD_END  │
     * ├────────────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────────────┬─────────┼─────────┤
     * │     KC_LSFT (2)     │ KC_Z    │ KC_X    │ KC_C    │ KC_V    │ KC_B    │ KC_N    │ KC_M    │ KC_COMM │ KC_DOT  │ KC_SLSH │     KC_RSFT     │ KC_UP   │ MO(_FN1)│
     * ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬┴────────┬─┴───────┬─────────┼─────────┼─────────┤
     * │  KC_LCTL  │  KC_LGUI  │  KC_LALT  │                            KC_SPC                             │ KC_RALT │ KC_RCTL │         │ KC_LEFT │ KC_DOWN │ KC_RGHT │
     * └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
     */
    [_QWERTY] = LAYOUT_all(
        QK_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSPC, KC_BSPC, KC_DEL,
        KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC, KC_BSLS, TD(TD_HOME),
        KC_CAPS, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_ENT, TD(TD_END),
        KC_LSFT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_UP, MO(_FN1),
        KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, KC_RCTL, KC_LEFT, KC_DOWN, KC_RGHT
    ),

    /* 1: _FN1
     * ┌─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬─────────┬───────────────────┬─────────┐
     * │ QK_BOOT   │ KC_F1   │ KC_F2   │ KC_F3   │ KC_F4   │ KC_F5   │ KC_F6   │ KC_F7   │ KC_F8   │ KC_F9   │ KC_F10  │ KC_F11  │ KC_F12  │    _______ (2)    │ KC_MUTE │
     * ├─────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬──────────────┼─────────┤
     * │   _______    │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ KC_PSCR │ _______ │ _______ │   _______    │ KC_VOLU │
     * ├──────────────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴─┬───────┴──────────────┼─────────┤
     * │    _______     │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │       _______        │ KC_VOLD │
     * ├────────────────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────┬────┴────────────┬─────────┼─────────┤
     * │     _______ (2)     │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │ _______ │     _______     │ KC_MPLY │ _______ │
     * ├───────────┬─────────┴─┬───────┴───┬─────┴─────────┴─────────┴─────────┴─────────┴─────────┴───────┬─┴───────┬─┴───────┬─┴───────┬─────────┼─────────┼─────────┤
     * │  _______  │  _______  │  _______  │                            _______                            │ _______ │ _______ │         │ KC_MPRV │ KC_MPLY │ KC_MNXT │
     * └───────────┴───────────┴───────────┴───────────────────────────────────────────────────────────────┴─────────┴─────────┴─────────┴─────────┴─────────┴─────────┘
     */
    [_FN1] = LAYOUT_all(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_MUTE,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______,          _______, KC_VOLU,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,          KC_VOLD,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          KC_MPLY, _______,
        _______, _______, _______,          _______,          _______,          _______,          _______, _______,          KC_MPRV, KC_MPLY, KC_MNXT
    )
};
