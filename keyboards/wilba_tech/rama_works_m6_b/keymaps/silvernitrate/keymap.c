#include QMK_KEYBOARD_H

// Define Layers
#define _SOUND 0
#define _PROGRAMS 1
#define _TEMP1 2
#define _TEMP2 3
#define _TEMP3 4
#define _LAYERS 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_SOUND] = LAYOUT(
        KC_1, KC_1, KC_1,
        KC_1, KC_1, MO(5)),

    [_PROGRAMS] = LAYOUT(
        KC_2, KC_2, KC_2,
        KC_2, KC_2, _______),

    [_TEMP1] = LAYOUT(
        KC_3, KC_3, KC_3,
        KC_3, KC_3, _______),

    [_TEMP2] = LAYOUT(
        KC_4, KC_4, KC_4,
        KC_4, KC_4, _______),

    [_TEMP3] = LAYOUT(
        KC_5, KC_5, RESET,
        KC_5, KC_5, _______),

    [_LAYERS] = LAYOUT(
        TO(0), TO(1), TO(2),
        TO(3), TO(4), _______)
};
    