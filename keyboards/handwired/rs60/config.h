/*
Copyright 2018 QMK Contributors

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

/* key matrix pins */
#define MATRIX_ROW_PINS { B5, B6, B4, B2, E6 }
#define MATRIX_COL_PINS { C6, D4, D0, D1, D2, D3,  F4, F5, F6, F7, B1, B3}

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* key combination for command */
#define IS_COMMAND() ( \
    false \
)
