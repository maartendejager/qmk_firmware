/* Copyright 2019 joaofbmaia
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  
  /* LAYER 0
  * ,-----------------------.
  * |  ESC  |   ~   | SPC/FN|  Hold for FN
  * |-------+-------+-------|
  * |   C   |   Z   |   X   |
  * `-------+-------+-------'
  */
  [0] = LAYOUT(
    KC_ESC, KC_GRAVE, LT(1, KC_SPC),
    KC_C, KC_Z, KC_X
  ),

  /* LAYER 1
  * ,-----------------------.
  * |RGB_TOG|RGBMOD+|       |
  * |-------+-------+-------|
  * |RGBHUE+|RGBBRI+|Spec FN|   Hold along with previous to access special funtions (QK_BOOT)
  * `-------+-------+-------'
  */
  [1] = LAYOUT(
    RGB_TOG, RGB_MOD, KC_TRNS,
    RGB_HUI, RGB_VAI, MO(2)
  ),

  /* LAYER 2
  * ,-----------------------.
  * | QK_BOOT |RGBMOD-|       |
  * |-------+-------+-------|
  * |RGBHUE-|RGBBRI-|       |
  * `-------+-------+-------'
  */
  [2] = LAYOUT(
    QK_BOOT, RGB_RMOD, KC_NO,
    RGB_HUD, RGB_VAD, KC_TRNS
  )
  
};
