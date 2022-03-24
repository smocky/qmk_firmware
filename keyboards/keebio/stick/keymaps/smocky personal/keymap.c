/*
Copyright 2021 Danny Nguyen <danny@keeb.io>

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

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _FUNCTION,
    _CONFIG
};

#define ZOOM_VIDEO_TOGGLE LGUI(LSFT(KC_V))
#define ZOOM_AUDIO_TOGGLE LGUI(LSFT(KC_A))
#define SLACK_MENTIONS_TOGGLE LGUI(LSFT(KC_M))
#define SLACK_HOME_WORKSPACE LGUI(KC_1)
#define SLACK_HISTORY_PREV LGUI(KC_LBRC)
#define SLACK_HISTORY_NEXT LGUI(KC_RBRC)
#define OSX_NOTIFICATIONS_SHORTCUT LCTL(KC_N)
#define OSX_AUDIO_OUTPUT_TOGGLE LGUI(KC_F13)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
        KC_BRIGHTNESS_DOWN,    KC_BRIGHTNESS_UP,    SLACK_MENTIONS_TOGGLE,    LT(_CONFIG,SLACK_HOME_WORKSPACE),    OSX_AUDIO_OUTPUT_TOGGLE,    KC_MPRV,    KC_MPRV,    KC_MPLY,    KC_MNXT,    KC_MUTE,   KC_VOLD,   KC_VOLU
    ),
    [_FUNCTION] = LAYOUT(
        KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12
    ),
    [_CONFIG] = LAYOUT(
        RGB_SAD,    RGB_SAI,    RESET,    _______,    RGB_HUD,    RGB_HUI,    RGB_RMOD,    RGB_TOG,    RGB_MOD,    RGB_MODE_PLAIN,   RGB_SPD,   RGB_SPI
//        _______,    RGB_MODE_PLAIN,    RGB_HUD,    RGB_HUI,    RGB_MODE_BREATHE,    RGB_RMOD,    RGB_SPD,    RGB_TOG,    RGB_SPI,    RGB_MOD,   KC_K,   RESET
    ),
};
