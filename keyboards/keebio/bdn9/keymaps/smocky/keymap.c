/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

enum bdn9_layer {
    _BASE = 0,
    _CODE,
    _RGB
};

enum encoder_names {
    _LEFT,
    _RIGHT
};

#define OSX_SPOTIFY_SHORTCUT LCTL(LALT(LGUI(KC_S)))
#define OSX_AUDIO_OUTPUT_TOGGLE LGUI(KC_F13)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
        | Knob 1: Vol Dn/Up |                                      | Knob 2: Page Dn/Up        |
        | Press: Mute       | Next Layer                           | Press: Toggle Zoom Video  |
        | Media Prev        | Play/Pause, Hold: SLACK layer        | Media Next                |
        | Notification Tray | Toggle Zoom Video, Hold: RGB Control | Toggle Audio Out Device   |
     */
    [_BASE] = LAYOUT(
        KC_MUTE, TO(_CODE), KC_MPLY,
        KC_MPRV, KC_MPLY, KC_MNXT,
        OSX_SPOTIFY_SHORTCUT, LT(_RGB, KC_MPLY), OSX_AUDIO_OUTPUT_TOGGLE),
    /*
    VSCODE CONTROLS
        | Press: Mute  | Next Layer         | Press: Toggle Zoom Video |
        | History Prev                   | N/A                | History Next             |
        | Toggle Slack Mentions          | Toggle Zoom Video  | Slack Home Workspace     |
     */
    [_CODE]   = LAYOUT(
        KC_MUTE, TO(_BASE), KC_MPLY,
        KC_C, KC_F5, KC_F10,
        LGUI(LSFT(KC_M)), LT(_RGB, KC_F11), LGUI(LSFT(KC_F5))
    ),
    [_RGB]    = LAYOUT(
        RGB_TOG, RGB_MODE_PLAIN, RESET,
        RGB_RMOD, RGB_TOG, RGB_MOD,
        RGB_SAD, _______, RGB_SAI
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        switch (biton32(layer_state)) {
            case _RGB:
                if (clockwise) {
                    rgblight_increase_val();
                } else {
                    rgblight_decrease_val();
                }
                break;
            default:
                if (clockwise) {
                    tap_code(KC_VOLU);
                } else {
                    tap_code(KC_VOLD);
                }
                break;
        }
    } else if (index == _RIGHT) {
        switch (biton32(layer_state)) {
/*            case _VIDEO:
                if (clockwise) {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    tap_code(KC_DOT);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LSFT);
                } else {
                    register_code(KC_LCTL);
                    register_code(KC_LSFT);
                    tap_code(KC_COMMA);
                    unregister_code(KC_LCTL);
                    unregister_code(KC_LSFT);
                }
                break;*/
            case _RGB:
                if (clockwise) {
                    rgblight_increase_hue();
                } else {
                    rgblight_decrease_hue();
                }
                break;
            case _CODE:
              if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            default:
                if (clockwise) {
                        tap_code(KC_BRIGHTNESS_UP);
                    } else {
                        tap_code(KC_BRIGHTNESS_DOWN);
                    }
                    break;
        }
    }
    return false;
}

// ADD IN BLINK FOR CHANGING LAYERS TO TEMP DO IT, AS WELL AS A KEYPRESS TO CONFIRM
// CURRENT LAYER WITH A BLINK
// On demand layer state blink
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
       /* case SHOW_LAYER:
            if (record->event.pressed) {
                rgblight_blink_layer(biton32(layer_state), 1000);
            }
            return false;*/
        default:
            return true;
    }
}
