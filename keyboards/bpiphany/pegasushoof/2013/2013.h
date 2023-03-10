/*
Copyright 2016 Daniel Svensson <dsvensson@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "matrix.h"
#include "quantum.h"

#define LAYOUT( \
    KJ6,      KI4, KH4, KH2, KH6, KA7, KE6, KD2, KD4, KB4, KB7, KB6, KB0,   KC7, KC5, KA5, \
    KJ4, KJ7, KI7, KH7, KG7, KG4, KF4, KF7, KE7, KD7, KR7, KR4, KE4, KB2,   KL4, KO4, KQ4, \
    KJ2, KJ5, KI5, KH5, KG5, KG2, KF2, KF5, KE5, KD5, KR5, KR2, KE2, KB3,   KK4, KO7, KQ7, \
    KI2, KJ3, KI3, KH3, KG3, KG6, KF6, KF3, KE3, KD3, KR3, KR6,      KB1,                  \
    KN2, KI6, KJ1, KI1, KH1, KG1, KG0, KF0, KF1, KE1, KD1, KR0,      KN3,        KO6,      \
    KA4, KP2, KC6,                KK6,                KC0, KM3, KD0, KA1,   KO0, KK0, KL0  \
    ) { /*         00-A   01-B   02-C   03-D   04-E   05-F   06-G   07-H   08-I   09-J   10-K   11-L   12-M   13-N   14-O   15-P   16-Q   17-R */  \
        /* 0 */  { KC_NO, KB0,   KC0,   KD0,   KC_NO, KF0,   KG0,   KC_NO, KC_NO, KC_NO, KK0,   KL0,   KC_NO, KC_NO, KO0,   KC_NO, KC_NO, KR0   }, \
        /* 1 */  { KA1,   KB1,   KC_NO, KD1,   KE1,   KF1,   KG1,   KH1,   KI1,   KJ1,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO }, \
        /* 2 */  { KC_NO, KB2,   KC_NO, KD2,   KE2,   KF2,   KG2,   KH2,   KI2,   KJ2,   KC_NO, KC_NO, KC_NO, KN2,   KC_NO, KP2,   KC_NO, KR2   }, \
        /* 3 */  { KC_NO, KB3,   KC_NO, KD3,   KE3,   KF3,   KG3,   KH3,   KI3,   KJ3,   KC_NO, KC_NO, KM3,   KN3,   KC_NO, KC_NO, KC_NO, KR3   }, \
        /* 4 */  { KA4,   KB4,   KC_NO, KD4,   KE4,   KF4,   KG4,   KH4,   KI4,   KJ4,   KK4,   KL4,   KC_NO, KC_NO, KO4,   KC_NO, KQ4,   KR4   }, \
        /* 5 */  { KA5,   KC_NO, KC5,   KD5,   KE5,   KF5,   KG5,   KH5,   KI5,   KJ5,   KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KR5   }, \
        /* 6 */  { KC_NO, KB6,   KC6,   KC_NO, KE6,   KF6,   KG6,   KH6,   KI6,   KJ6,   KK6,   KC_NO, KC_NO, KC_NO, KO6,   KC_NO, KC_NO, KR6   }, \
        /* 7 */  { KA7,   KB7,   KC7,   KD7,   KE7,   KF7,   KG7,   KH7,   KI7,   KJ7,   KC_NO, KC_NO, KC_NO, KC_NO, KO7,   KC_NO, KQ7,   KR7   }  \
    }

#define LAYOUT_tkl_ansi( \
    KG6,      KH4, KI4, KI2, KI6, KP5, KL6, KM2, KM4, KO4, KO5, KO6, KO0,   KN5, KN7, KP7, \
    KG4, KG5, KH5, KI5, KJ5, KJ4, KK4, KK5, KL5, KM5, KF5, KF4, KL4, KO2,   KR4, KC4, KE4, \
    KG2, KG7, KH7, KI7, KJ7, KJ2, KK2, KK7, KL7, KM7, KF7, KF2, KL2, KO3,   KQ4, KC5, KE5, \
    KH2, KG3, KH3, KI3, KJ3, KJ6, KK6, KK3, KL3, KM3, KF3, KF6,      KO1,                  \
    KB2,      KG1, KH1, KI1, KJ1, KJ0, KK0, KK1, KL1, KM1, KF0,      KB3,        KC6,      \
    KP4, KD2, KN6,                KQ6,                KN0, KA3, KM0, KP1,   KC0, KQ0, KR0  \
    ) { /*         00-A   01-B   02-C   03-D   04-E  05-F    06-G   07-H   08-I   09-J   10-K   11-L   12-M   13-N   14-O   15-P   16-Q   17-R */  \
        /* 0 */  { KC_NO, KC_NO, KC0,   KC_NO, KC_NO, KF0,   KC_NO, KC_NO, KC_NO, KJ0,   KK0,   KC_NO, KM0,   KN0,   KO0,   KC_NO, KQ0,   KR0   }, \
        /* 1 */  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KG1,   KH1,   KI1,   KJ1,   KK1,   KL1,   KM1,   KC_NO, KO1,   KP1,   KC_NO, KC_NO }, \
        /* 2 */  { KC_NO, KB2,   KC_NO, KD2,   KC_NO, KF2,   KG2,   KH2,   KI2,   KJ2,   KK2,   KL2,   KM2,   KC_NO, KO2,   KC_NO, KC_NO, KC_NO }, \
        /* 3 */  { KA3,   KB3,   KC_NO, KC_NO, KC_NO, KF3,   KG3,   KH3,   KI3,   KJ3,   KK3,   KL3,   KM3,   KC_NO, KO3,   KC_NO, KC_NO, KC_NO }, \
        /* 4 */  { KC_NO, KC_NO, KC4,   KC_NO, KE4,   KF4,   KG4,   KH4,   KI4,   KJ4,   KK4,   KL4,   KM4,   KC_NO, KO4,   KP4,   KQ4,   KR4   }, \
        /* 5 */  { KC_NO, KC_NO, KC5,   KC_NO, KE5,   KF5,   KG5,   KH5,   KI5,   KJ5,   KK5,   KL5,   KM5,   KN5,   KO5,   KP5,   KC_NO, KC_NO }, \
        /* 6 */  { KC_NO, KC_NO, KC6,   KC_NO, KC_NO, KF6,   KG6,   KC_NO, KI6,   KJ6,   KK6,   KL6,   KC_NO, KN6,   KO6,   KC_NO, KQ6,   KC_NO }, \
        /* 7 */  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KF7,   KG7,   KH7,   KI7,   KJ7,   KK7,   KL7,   KM7,   KN7,   KC_NO, KP7,   KC_NO, KC_NO }  \
    }

#define LAYOUT_tkl_jis( \
    KG6,      KH4, KI4, KI2, KI6, KP5, KL6, KM2, KM4, KO4, KO5, KO6, KO0,        KN5, KN7, KP7, \
    KG4, KG5, KH5, KI5, KJ5, KJ4, KK4, KK5, KL5, KM5, KF5, KF4, KL4, KO7, KO2,   KR4, KC4, KE4, \
    KG2, KG7, KH7, KI7, KJ7, KJ2, KK2, KK7, KL7, KM7, KF7, KF2, KL2,             KQ4, KC5, KE5, \
    KH2, KG3, KH3, KI3, KJ3, KJ6, KK6, KK3, KL3, KM3, KF3, KF6, KO3, KO1,                       \
    KB2,      KG1, KH1, KI1, KJ1, KJ0, KK0, KK1, KL1, KM1, KF0, KL0, KB3,             KC6,      \
    KP4, KD2, KN6, KG0,           KQ6,           KH0, KI0, KN0, KM0, KP1,        KC0, KQ0, KR0  \
    ) { /*         00-A   01-B   02-C   03-D   04-E   05-F   06-G   07-H   08-I   09-J   10-K   11-L   12-M   13-N   14-O   15-P   16-Q   17-R */ \
        /* 0 */  { KC_NO, KC_NO, KC0,   KC_NO, KC_NO, KF0,   KG0,   KH0,   KI0,   KJ0,   KK0,   KL0,   KM0,   KN0,   KO0,   KC_NO, KQ0,   KR0   },\
        /* 1 */  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KG1,   KH1,   KI1,   KJ1,   KK1,   KL1,   KM1,   KC_NO, KO1,   KP1,   KC_NO, KC_NO },\
        /* 2 */  { KC_NO, KB2,   KC_NO, KD2,   KC_NO, KF2,   KG2,   KH2,   KI2,   KJ2,   KK2,   KL2,   KM2,   KC_NO, KO2,   KC_NO, KC_NO, KC_NO },\
        /* 3 */  { KC_NO, KB3,   KC_NO, KC_NO, KC_NO, KF3,   KG3,   KH3,   KI3,   KJ3,   KK3,   KL3,   KM3,   KC_NO, KO3,   KC_NO, KC_NO, KC_NO },\
        /* 4 */  { KC_NO, KC_NO, KC4,   KC_NO, KE4,   KF4,   KG4,   KH4,   KI4,   KJ4,   KK4,   KL4,   KM4,   KC_NO, KO4,   KP4,   KQ4,   KR4   },\
        /* 5 */  { KC_NO, KC_NO, KC5,   KC_NO, KE5,   KF5,   KG5,   KH5,   KI5,   KJ5,   KK5,   KL5,   KM5,   KN5,   KO5,   KP5,   KC_NO, KC_NO },\
        /* 6 */  { KC_NO, KC_NO, KC6,   KC_NO, KC_NO, KF6,   KG6,   KC_NO, KI6,   KJ6,   KK6,   KL6,   KC_NO, KN6,   KO6,   KC_NO, KQ6,   KC_NO },\
        /* 7 */  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KF7,   KG7,   KH7,   KI7,   KJ7,   KK7,   KL7,   KK7,   KL7,   KO7,   KP7,   KC_NO, KC_NO } \
}
