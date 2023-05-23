<<<<<<<< HEAD:keyboards/balloondogcaps/tr90/keymaps/default/keymap.c
/* Copyright 2021 Balloondog
========
/* Copyright 2022 Jesus Climent  (@climent)
>>>>>>>> upstream/master:keyboards/atreyu/keymaps/default/config.h
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

<<<<<<<< HEAD:keyboards/balloondogcaps/tr90/keymaps/default/keymap.c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT( /* Base */
        KC_1,  KC_2, KC_3,
        KC_4,  KC_5, KC_6,
        KC_VOLD,  KC_VOLU, MO(1)
    ),
    [1] = LAYOUT(
        KC_7, KC_8, KC_9,
        KC_0, KC_MINUS, KC_PLUS,
        RESET, KC_AT , KC_TRNS
    ),
};

========
#pragma once


// place overrides here
#ifdef TAPPING_TERM
#undef TAPPING_TERM
#define TAPPING_TERM 150
#endif
>>>>>>>> upstream/master:keyboards/atreyu/keymaps/default/config.h

#define RETRO_TAPPING
