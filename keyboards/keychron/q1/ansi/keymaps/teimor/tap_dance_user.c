/* Copyright 2022 @ Teimor Epstein
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

#include "keymap_user.h"
#include "tap_dance_mac_caps.h"
#include "tap_dance_win_caps.h"

// clang-format off

tap_dance_action_t tap_dance_actions[] = {
    [MAC_CAPS_LANGUAGE_CHANGE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, mac_caps_language_finished, mac_caps_language_reset),
    [WIN_CAPS_LANGUAGE_CHANGE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, win_caps_language_finished, win_caps_language_reset)
};

// clang-format on
