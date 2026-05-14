/* Copyright 2015-2017 Jack Humbert
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
#include "print.h"



enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _WORK,
  _TESTNAV
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  ZOOM_VIDEO,
  ZOOM_AUDIO,
  SLACK_MENTIONS,
  SLACK_HOME_WORKSPACE,
  SLACK_HISTORY_PREV,
  SLACK_HISTORY_NEXT,
  OSX_AUDIO_OUTPUT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

#ifdef RGB_MATRIX_ENABLE
#    define SM_RGB_TOG RM_TOGG
#    define SM_RGB_MOD RM_NEXT
#    define SM_RGB_HUI RM_HUEU
#    define SM_RGB_HUD RM_HUED
#    define SM_RGB_SAI RM_SATU
#    define SM_RGB_SAD RM_SATD
#    define SM_RGB_VAI RM_VALU
#    define SM_RGB_VAD RM_VALD
#    define SM_RGB_BREATHE RM_NEXT
#else
#    define SM_RGB_TOG UG_TOGG
#    define SM_RGB_MOD UG_NEXT
#    define SM_RGB_HUI UG_HUEU
#    define SM_RGB_HUD UG_HUED
#    define SM_RGB_SAI UG_SATU
#    define SM_RGB_SAD UG_SATD
#    define SM_RGB_VAI UG_VALU
#    define SM_RGB_VAD UG_VALD
#    define SM_RGB_BREATHE RGB_M_B
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |SFT/Cap|  Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |  / |Enter/SFT|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | RGB  | Ctrl/ESC | Alt  | GUI  |Lower |Space |Bksp/Work|Raise| Left | Down |Up | Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    QK_GESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    LSFT_T(KC_CAPS), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_ENT),
   LT(_TESTNAV,SM_RGB_TOG), LCTL_T(KC_ESC), KC_LALT, KC_LGUI, LOWER,   KC_SPC,   LT(_WORK,KC_BSPC),  RAISE, KC_LEFT, KC_DOWN, KC_UP,LT(_TESTNAV, KC_RGHT)
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |BREATHE|      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_MPLY,
    SM_RGB_BREATHE, _______, _______, _______, _______, _______, _______, _______,    KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn | Play |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Prev | Vol- | Vol+ | Next |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME,    KC_PGDN, KC_PGUP, KC_END
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty| | | |      |KC_ASON
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, SM_RGB_TOG, SM_RGB_MOD, SM_RGB_HUI, SM_RGB_HUD, SM_RGB_SAI, SM_RGB_SAD, SM_RGB_VAI, SM_RGB_VAD, KC_DEL,
    _______, _______, MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  _______, _______, _______, _______,
    _______, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, AS_TOGG, AS_DOWN, AS_UP,   AS_RPT
),

[_WORK] = LAYOUT_planck_grid(
    _______, _______,   _______,   _______, _______, _______, _______, _______, _______,  _______, _______, _______,
    _______, ZOOM_AUDIO, _______, _______,   _______,  _______, SLACK_HOME_WORKSPACE,_______, _______,  _______, _______, _______,
    _______, SLACK_HISTORY_PREV,  SLACK_HISTORY_NEXT,  _______,   ZOOM_VIDEO,  _______,   _______,  SLACK_MENTIONS, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),[_TESTNAV] = LAYOUT_planck_grid(
    _______, _______,   KC_UP,   _______, KC_PGUP, _______, _______, _______, KC_UP,  _______, _______, _______,
    _______, KC_LEFT, KC_DOWN, KC_RIGHT,   KC_PGDN,  _______, _______,KC_LEFT, KC_DOWN, KC_RIGHT, _______, _______,
    _______, _______,  _______,  _______,   _______,  _______,   _______,  _______, _______,  _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)
/*
[_WORK] = LAYOUT_planck_grid(
    _______, _______,   _______,   _______, _______, _______, _______, KC_7, KC_8, KC_9, KC_0, _______ ,
    _______, ZOOM_AUDIO, _______,  _______,   _______,  _______, _______, KC_4, KC_5,  KC_6,  KC_PLUS,  _______,
    _______, ZOOM_VIDEO,  _______,  _______,   _______,  _______,   _______,  KC_1, KC_2, KC_3, KC_MINUS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_0, _______, _______
)*/

};

#ifdef AUDIO_ENABLE
  float plover_song[][2]     = SONG(PLOVER_SOUND);
  float plover_gb_song[][2]  = SONG(PLOVER_GOODBYE_SOUND);
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case ZOOM_VIDEO:
        if(record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("v")));
        } else {
            // released
        }
        break;
     case ZOOM_AUDIO:
        if(record->event.pressed) {
            SEND_STRING(SS_LGUI(SS_LSFT("a")));
        } else {
            // released
        }
        break;
      case SLACK_MENTIONS:
        if(record->event.pressed) {
          SEND_STRING(SS_LGUI(SS_LSFT("m")));
        } else {
            // released
        }
        break;
      case SLACK_HOME_WORKSPACE:
        if(record->event.pressed) {
          SEND_STRING(SS_LGUI("1"));
        } else {
            // released
        }
        break;
      case SLACK_HISTORY_PREV:
        if(record->event.pressed) {
          SEND_STRING(SS_LGUI("["));
        } else {
            // released
        }
        break;
      case SLACK_HISTORY_NEXT:
        if(record->event.pressed) {
          SEND_STRING(SS_LGUI("]"));
        } else {
            // released
        }
        break;
       case OSX_AUDIO_OUTPUT:
        if(record->event.pressed) {
          tap_code16(LGUI(KC_F13));
        } else {
            // released
        }
        break;
  }
  return true;
}

#ifdef RGBLIGHT_LAYERS
// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8, 1, HSV_WHITE}       // Light 4 LEDs, starting with LED 6
//    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
#endif

bool led_update_user(led_t led_state) {
#ifdef RGBLIGHT_LAYERS
    rgblight_set_layer_state(0, led_state.caps_lock);
#endif
    return true;
}

/*
layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, _DVORAK));ß
    return state;
}
*/
layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}


bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLD);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(MS_WHLU);
      #else
        tap_code(KC_PGUP);
      #endif
    }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_song); }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) { PLAY_SONG(plover_gb_song); }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
        case 1:
            break;
    }
    return true;
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}
