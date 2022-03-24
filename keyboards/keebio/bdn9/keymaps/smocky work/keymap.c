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
    _SLACK,
    _CODE,
    _RGB
};

enum encoder_names {
    _LEFT,
    _RIGHT
};


enum my_keycode {
  //  SHOW_LAYER = SAFE_RANGE
  ZOOM_AUDIO_TOGGLE = SAFE_RANGE
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
    /*
        | Knob 1: Vol Dn/Up |                                      | Knob 2: Page Dn/Up        |
        | Press: Mute       | Next Layer                           | Press: Toggle Zoom Video  |
        | Media Prev        | Play/Pause, Hold: SLACK layer        | Media Next                |
        | Notification Tray | Toggle Zoom Video, Hold: RGB Control | Toggle Audio Out Device   |
     */
    [_BASE] = LAYOUT(
        KC_MUTE, TO(_CODE), ZOOM_VIDEO_TOGGLE,
        KC_MPRV, LT(_SLACK, KC_MPLY), KC_MNXT,
        OSX_NOTIFICATIONS_SHORTCUT, LT(_RGB, ZOOM_VIDEO_TOGGLE), OSX_AUDIO_OUTPUT_TOGGLE),
    /*
    SLACK CONTROLS
        | Press: Zoom Audio Mute Toggle  | Next Layer         | Press: Toggle Zoom Video |
        | History Prev                   | N/A                | History Next             |
        | Toggle Slack Mentions          | Toggle Zoom Video  | Slack Home Workspace     |
     */
    [_SLACK]  = LAYOUT(
        ZOOM_AUDIO_TOGGLE, TO(_CODE), ZOOM_VIDEO_TOGGLE,
        SLACK_HISTORY_PREV, _______, SLACK_HISTORY_NEXT,
        SLACK_MENTIONS_TOGGLE, ZOOM_VIDEO_TOGGLE, SLACK_HOME_WORKSPACE
    ),
    /*
    VSCODE CONTROLS
        | Press: Mute  | Next Layer         | Press: Toggle Zoom Video |
        | History Prev                   | N/A                | History Next             |
        | Toggle Slack Mentions          | Toggle Zoom Video  | Slack Home Workspace     |
     */
    [_CODE]   = LAYOUT(
        KC_MUTE, TO(_BASE), ZOOM_VIDEO_TOGGLE,
        KC_C, LT(_SLACK, KC_F5), KC_F10,
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
            case _SLACK:
                if (clockwise) {
                    tap_code(KC_BRIGHTNESS_UP);
                } else {
                    tap_code(KC_BRIGHTNESS_DOWN);
                }
                break;
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
            case _SLACK:
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

// RGB Layers
const rgblight_segment_t PROGMEM my_base_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_slack_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_YELLOW}
);

const rgblight_segment_t PROGMEM my_code_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}
);
/*
const rgblight_segment_t PROGMEM my_video_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_BLUE}
);
*/
const rgblight_segment_t PROGMEM my_zoom_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 4, HSV_RED}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_base_layer,
    my_slack_layer,
    my_code_layer,
 //   my_video_layer,
    my_zoom_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

// Blink out the layer state
layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
   /* rgblight_set_layer_state(0, layer_state_cmp(state, _SLACK));
    rgblight_set_layer_state(1, layer_state_cmp(state, _CODE));
    rgblight_set_layer_state(2, layer_state_cmp(state, _VIDEO));
    rgblight_set_layer_state(3, layer_state_cmp(state, _ZOOM));*/

    rgblight_blink_layer(get_highest_layer(state), 500);

    return state;
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
        case ZOOM_AUDIO_TOGGLE:
                    if (record->event.pressed) {
                        register_code(KC_LGUI);
                        register_code(KC_LSFT);
                        tap_code(KC_A);
                        unregister_code(KC_LGUI);
                        unregister_code(KC_LSFT);
                      //  rgblight_blink_layer(3, 1000);
                      rgblight_mode(4);
                    }
            return false;
        default:
            return true;
    }
}
