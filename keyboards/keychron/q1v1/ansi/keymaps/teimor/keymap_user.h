<<<<<<<< HEAD:keyboards/keychron/q1/rev_0100/keymaps/teimor/keymap_user.h
/* Copyright 2022 @ Teimor Epstein
========
/* Copyright 2022 Yiancar
>>>>>>>> upstream/master:keyboards/novelkeys/nk20/nk20.h
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
#pragma once

<<<<<<<< HEAD:keyboards/keychron/q1/rev_0100/keymaps/teimor/keymap_user.h
// clang-format off

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN
};

// clang-format on

// Tap dance enums
enum {
    MAC_CAPS_LANGUAGE_CHANGE,
    WIN_CAPS_LANGUAGE_CHANGE,
};

#ifdef TAP_DANCE_ENABLE
#   define KC_LGMAC TD(MAC_CAPS_LANGUAGE_CHANGE)
#   define KC_LGWIN TD(WIN_CAPS_LANGUAGE_CHANGE)
#else
#   define KC_LGMAC KC_CAPS
#   define KC_LGWIN KC_CAPS
#endif
#define KC_MACFN MO(MAC_FN)
#define KC_WINFN MO(WIN_FN)
#define KC_LMAC C(G(KC_Q))
#define KC_MACPS G(S(KC_5))
#define KC_TASK G(KC_TAB)
#define KC_FLXP G(KC_E)
========
#define XXX KC_NO

#include "quantum.h"

// This a shortcut to help you visually see your layout.

#define LAYOUT_all( \
    K00, K01, K02,      \
    K10, K11, K12, K13, \
    K20, K21, K22, K23, \
    K30, K31, K32,      \
    K40, K41, K42, K43, \
    K50,      K52       \
) { \
    { K00, K01, K02, XXX }, \
    { K10, K11, K12, K13 }, \
    { K20, K21, K22, K23 }, \
    { K30, K31, K32, XXX }, \
    { K40, K41, K42, K43 }, \
    { K50, XXX, K52, XXX }, \
}
>>>>>>>> upstream/master:keyboards/novelkeys/nk20/nk20.h
