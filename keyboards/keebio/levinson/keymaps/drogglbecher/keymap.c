#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#define _FN0 0
#define _FN1 1
#define _FN2 2

#define KC_X1 MO(_FN1)
#define KC_X2 MO(_FN2)

#define KC_LPRN LSFT(KC_9)      // (
#define KC_RPRN LSFT(KC_0)      // )


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* ┌──────┬──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┬──────┐
    * │ ESC  │  q   │  w   │  e   │  r   │  t   │ │  y   │  u   │  i   │  o   │  p   │ BS   │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │ CTRL │  a   │  s   │  d   │  f   │  g   │ │  h   │  j   │  k   │  l   │ " '  │ RET  │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │ SHFT │  z   │  x   │  c   │  v   │  b   │ │  n   │  m   │ [ {  │ ] }  │ ; :  │ SHFT │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │ L1   │ ALT  │  L2  │ TAB  | SPC  │ SPC  │ │ SPC  │ SPC  │ , <  │ . >  │ - _  │ / ?  │
    * └──────┴──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┴──────┘
    */

  [_FN0] = LAYOUT_ortho_4x12(
     KC_ESC,   KC_Q,      KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
     KC_LCTL,  KC_A,      KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_QUOT,    KC_ENT,
     KC_LSFT,  KC_Z,      KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_LBRC,    KC_RBRC,    KC_SCLN,    KC_RSFT,
     KC_X1,    KC_LALT,   KC_X2,      KC_TAB,     KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     KC_COMM,    KC_DOT,     KC_MINS,    KC_SLSH
  ),

   /* ┌──────┬──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┬──────┐
    * │      │  1   │  2   │  3   │  4   │  5   │ │  6   │  7   │  8   │  9   │  0   │ DEL  │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │      │  ä   │  ö   │  ü   │  ß   │      │ │ LEFT │ DOWN │  UP  │ RGT  │      │      │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │      │  Ä   │  Ö   │  Ü   │  €   │      │ │      │      │  (   │  )   │      │      │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │      |      │      │      | SPC  │ SPC  │ │ SPC  │ SPC  │      │      │      │  \ | │
    * └──────┴──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┴──────┘
    */

  [_FN1] = LAYOUT_ortho_4x12(
    _______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_DEL,
    _______,    UC(L'ä'),   UC(L'ö'),   UC(L'ü'),   UC(L'ß'),   _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,    KC_PIPE,
    _______,    UC(L'Ä'),   UC(L'Ö'),   UC(L'Ü'),   UC(L'€'),   _______,    _______,    _______,    KC_LPRN,    KC_RPRN,    _______,    _______,
    _______,    _______,    _______,    KC_TAB,     KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     _______,    _______,    _______,    KC_BSLS
  ),

   /* ┌──────┬──────┬──────┬──────┬──────┬──────┐ ┌──────┬──────┬──────┬──────┬──────┬──────┐
    * │  `   │  !   │  @   │  #   │  $   │  %   │ │  ^   │  &   │  *   │  ~   │  +   │  =   │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │      │      │      │      │      │      │ │ HOME │ PGDN │ PGUP │ END  │      │      │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │  F1  │  F2  │  F3  │  F4  │  F5  │  F6  │ │  F7  │  F8  │  F9  │ F10  │ F11  │ F12  │
    * ├──────┼──────┼──────┼──────┼──────┼──────┤ ├──────┼──────┼──────┼──────┼──────┼──────┤
    * │      │      │      │      │ SPC  │ SPC  │ │ SPC  │ SPC  │      │ VOL+ │ VOL- │ MUTE │
    * └──────┴──────┴──────┴──────┴──────┴──────┘ └──────┴──────┴──────┴──────┴──────┴──────┘
    */

  [_FN2] = LAYOUT_ortho_4x12(
     KC_GRV,    KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_TILD,    KC_PLUS,    KC_PEQL,
     _______,   _______,    _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    _______,
     KC_F1,     KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,
     _______,   _______,    _______,    _______,    KC_SPC,     KC_SPC,     KC_SPC,     KC_SPC,     _______,    KC_VOLD,    KC_VOLU,    KC_MUTE
  )

};

void matrix_init_user(void) {
    set_unicode_input_mode(UNICODE_MODE_LINUX);
};
