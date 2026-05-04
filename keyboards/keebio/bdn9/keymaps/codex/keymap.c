// Copyright 2026 David Smock
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _BASE,
    _CONFIG
};

enum encoder_names {
    _LEFT,
    _RIGHT
};

// Unique chords intended for Codex App or macOS shortcut binding.
#define CODEX_COMMIT LGUI(LALT(LCTL(LSFT(KC_C))))
#define CODEX_MODEL_55_HIGH LGUI(LALT(LCTL(LSFT(KC_5))))
#define CODEX_NEW_CHAT LGUI(LALT(LCTL(LSFT(KC_N))))
#define CODEX_INCREASE_TEST_COVERAGE LGUI(LALT(LCTL(LSFT(KC_T))))
#define CODEX_RIGHT_ACTION LGUI(LALT(LCTL(LSFT(KC_R))))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*
     * | Commit       | Stop Media     | GPT-5.5 High |
     * | New Chat     | Test Coverage  | Right Action |
     * | Mute         | Play/Pause     | Config       |
     */
    [_BASE] = LAYOUT(
        CODEX_COMMIT, KC_STOP, CODEX_MODEL_55_HIGH,
        CODEX_NEW_CHAT, CODEX_INCREASE_TEST_COVERAGE, CODEX_RIGHT_ACTION,
        KC_MUTE, KC_MPLY, MO(_CONFIG)
    ),

    [_CONFIG] = LAYOUT(
        RGB_TOG, RGB_M_P, QK_BOOT,
        RGB_RMOD, RGB_TOG, RGB_MOD,
        RGB_SAD, _______, RGB_SAI
    )
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == _LEFT) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == _RIGHT) {
        if (layer_state_is(_CONFIG)) {
            if (clockwise) {
                tap_code16(RGB_HUI);
            } else {
                tap_code16(RGB_HUD);
            }
        } else {
            if (clockwise) {
                tap_code(KC_PGDN);
            } else {
                tap_code(KC_PGUP);
            }
        }
    }
    return false;
}
