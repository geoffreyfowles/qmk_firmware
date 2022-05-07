/*
Copyright 2017 Danny Nguyen <danny@keeb.io>

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

// #define USE_I2C
#define EE_HANDS

// NOTE custom code below

#define FORCE_NKRO
#define DYNAMIC_MACRO_NO_NESTING
#define RGBLIGHT_SLEEP

// mouse keys
// TODO use kinetic once implemented properly
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_DELAY 0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED 7
#define MOUSEKEY_WHEEL_DELAY 0

// for home row modifiers
#define TAPPING_TERM 250
#define IGNORE_MOD_TAP_INTERRUPT
#define PERMISSIVE_HOLD
#define TAPPING_FORCE_HOLD

// for layer tap-hold keys
#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// saving space
#undef RGBLIGHT_ANIMATIONS

// rgb matrix animations
#define ENABLE_RGB_MATRIX_BREATHING
