/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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


/* NCC-1701-KB PCB default pin-out */
#define MATRIX_ROW_PINS { D4, D6, D7 }
#define MATRIX_COL_PINS { B4, B5, B6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION ROW2COL

#define TAPPING_TERM 200
