/* Copyright 2020 Sergi Meseguer <zigotica@gmail.com>

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


#ifdef OLED_ENABLE
  #define OLED_DISPLAY_128X32
#endif

// EC11 encoders' resolution.
// Reduce the value to 2 if you feel missing values:
#define ENCODER_RESOLUTION 4

// Allows correct registered values by rotary encoder:
#define TAP_CODE_DELAY 10
