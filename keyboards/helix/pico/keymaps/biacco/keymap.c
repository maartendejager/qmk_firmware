/* Copyright 2018 Biacco42
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_number {
    BASE = 0,
    META,
    SYMB,
    GAME
};

//Macros

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | GUI  | App  | PrtSc| ESC/ |Space/|Tab/  |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      | ~SYMB|RCtrl |Shift |Space |~META |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */

[BASE] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,             KC_T,                                     KC_Y,             KC_U,    KC_I,    KC_O,     KC_P,       KC_LBRC,
      KC_LALT, KC_A,    KC_S,    KC_D,    KC_F,             KC_G,                                     KC_H,             KC_J,    KC_K,    KC_L,     KC_SCLN,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,             KC_B,                                     KC_N,             KC_M,    KC_COMM, KC_DOT,   KC_SLSH,    SFT_T(KC_INT1) ,
      KC_LCTL, KC_LGUI, KC_APP,  KC_PSCR, LT(SYMB, KC_ESC), RCTL_T(KC_SPC), SFT_T(KC_TAB),  KC_BSPC,  LT(META, KC_ENT), KC_DEL,  KC_PSCR, TG(GAME), TG(SYMB),   KC_INT3
      ),

  /* META
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   1  |   2  |   3  |   4  |   5  |   6  |             |   7  |   8  |   9  |   0  |   -  |  ^   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Alt  |  F1  |      |Muhen | Henk |      |             | Left | Down |  Up  |Right |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Sft  |  F2  |  F3  |  F4  |  F5  |  F6  |             |  F7  |  F8  |  F9  | F10  | F11  |\/Sft |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |Back  |Enter/| Del  |Reset |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |~SYMB |RCtrl |Shift |Space |~META |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [META] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,                      KC_7,    KC_8,    KC_9,  KC_0,    KC_MINS, KC_EQL,
    _______, KC_F1,   XXXXXXX, KC_INT5, KC_INT4, XXXXXXX,                   KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, XXXXXXX, XXXXXXX,
    _______, KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9, KC_F10,  KC_F11,  SFT_T(KC_INT1),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, QK_BOOT, _______, _______, _______
  ),

  /* SYMB
   * ,-----------------------------------------.             ,-----------------------------------------.
   * |   !  |   "  |   #  |   $  |   %  |   &  |             |   '  |   (  |   )  |   ~  |   =  |  ~   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Alt  |      |      |      |      |      |             |   (  |   )  |   {  |   }  |   +  |  *   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Sft  |      |      |      |      |      |             |   [  |   ]  |   <  |   >  |   ?  |  \   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc |ESC/  |Space/|Tab/  |Back  |Enter/| Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |~SYMB |RCtrl |Shift |Space |~META |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [SYMB] = LAYOUT(
    S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),                   S(KC_7), S(KC_8), S(KC_9),    S(KC_0),    S(KC_MINS), S(KC_EQL),
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   S(KC_8), S(KC_9), S(KC_RBRC), S(KC_BSLS), S(KC_SCLN), S(KC_QUOT),
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_RBRC, KC_BSLS, S(KC_COMM), S(KC_DOT),  S(KC_SLSH), S(KC_INT1),
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______,   _______,    _______
  ),

  /* GAME
   * ,-----------------------------------------.             ,-----------------------------------------.
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |             |   Y  |   U  |   I  |   O  |   P  |  @   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Alt  |   A  |   S  |   D  |   F  |   G  |             |   H  |   J  |   K  |   L  |   ;  |  :   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | Sft  |   Z  |   X  |   C  |   V  |   B  |             |   N  |   M  |   ,  |   .  |   /  |\/Sft |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------+------|
   * | Ctrl | GUI  |  App |PrtSc | ESC  |Space |Tab   |Back  |Enter | Del  |PrtSc |=>GAME|=>SYMB|  \   |
   * |      |      |      |      |      |      |      |Space |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
   */
  [GAME] = LAYOUT(
    KC_TAB,   KC_Q,    KC_W,   KC_E,    KC_R,   KC_T,                           KC_Y,   KC_U,    KC_I,     KC_O,    KC_P,    KC_LBRC,
    KC_LALT,  KC_A,    KC_S,   KC_D,    KC_F,   KC_G,                           KC_H,   KC_J,    KC_K,     KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,  KC_Z,    KC_X,   KC_C,    KC_V,   KC_B,                           KC_N,   KC_M,    KC_COMM,  KC_DOT,  KC_SLSH, SFT_T(KC_INT1),
    KC_LCTL,  KC_LGUI, KC_APP, KC_PSCR, KC_ESC, KC_SPC, KC_TAB,     KC_BSPC,    KC_ENT, KC_DEL,  KC_PSCR,  _______, _______, KC_INT3
  )

};
