#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2

enum custom_keycodes {
    QWERTY = SAFE_RANGE,
    LOWER,
    RAISE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
   *  q   w   e    r    t        ||       y     u    i  o   p
   *  a   s   d    f    g        ||       h     j    k  l   ;
   *  z   x   c    v    b        ||       n     m    ,  .   /
   * esc tab gui shift bksp ctrl || alt space lower  -  ' enter
   */
  [_QWERTY] = LAYOUT(
    KC_Q,   KC_W,   KC_E,    KC_R,    KC_T,                      KC_Y,   KC_U,  KC_I,    KC_O,    KC_P,
    KC_A,   KC_S,   KC_D,    KC_F,    KC_G,                      KC_H,   KC_J,  KC_K,    KC_L,    KC_SCLN,
    KC_Z,   KC_X,   KC_C,    KC_V,    KC_B,                      KC_N,   KC_M,  KC_COMM, KC_DOT,  KC_SLSH,
    KC_ESC, KC_TAB, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC, LOWER, KC_MINS, KC_QUOT, KC_ENT
  ),

  /*
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * raise  insert  gui  shift bksp ctrl || alt space  ____   .     0    =
   */
  [_LOWER] = LAYOUT(
    KC_EXLM, KC_AT,   KC_UP,   KC_LCBR, KC_RCBR,                   KC_PGUP, KC_7,    KC_8,   KC_9, KC_ASTR,
    KC_HASH, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,                    KC_PGDN, KC_4,    KC_5,   KC_6, KC_PLUS,
    KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, KC_AMPR,                   KC_GRV,  KC_1,    KC_2,   KC_3, KC_BSLS,
    RAISE,   KC_INS,  KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_DOT, KC_0, KC_EQL
  ),

  /*
   * insert home   up   end  pgup       ||      up      F7    F8     F9    F10
   *  del   left  down right pgdn       ||     down     F4    F5     F6    F11
   *       volup             reset      ||              F1    F2     F3    F12
   *       voldn super shift bksp  ctrl || alt space QWERTY  prtsc scroll pause
   */
  [_RAISE] = LAYOUT(
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,  KC_F8,   KC_F9,   KC_F10,
    KC_DEL,  KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,  KC_F5,   KC_F6,   KC_F11,
    KC_TRNS, KC_VOLU, KC_TRNS, KC_TRNS, QK_BOOT,                   KC_TRNS, KC_F1,  KC_F2,   KC_F3,   KC_F12,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LCTL, KC_LALT, KC_SPC,  QWERTY, KC_PSCR, KC_SCRL, KC_PAUS
  ),
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  // The value to return
  bool return_value = false;

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      break;

    case LOWER:
      // Toggle LOWER layer on when key pressed and off when released
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      break;

    case RAISE:
      if (record->event.pressed) {
        persistent_default_layer_set(1UL<<_RAISE);
      }
      break;

    default:

      // If the keycode is not handled by any of the other cases, the
      // function should return true
      return_value = true;
      break;
  }

  return return_value;
}
