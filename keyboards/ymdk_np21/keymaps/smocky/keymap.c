#include QMK_KEYBOARD_H

enum layer_names {
    _NP,
    _NUMLOCK,
    _WORK,
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
    [_NP] = LAYOUT_ortho_6x4(
        LT(_CONFIG, KC_ESC),  KC_F2,  KC_TAB, KC_BSPC,
        TG(_NUMLOCK), KC_PSLS, KC_PAST, KC_PMNS,
        KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_P4,   KC_P5,   KC_P6,   KC_PPLS,
        KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_P0,   KC_DOT,  KC_PDOT, KC_PENT
    ),
    [_NUMLOCK] LAYOUT_ortho_6x4(
        LT(_CONFIG, KC_ESC),  KC_F2,  KC_TAB, KC_BSPC,
        TG(_NUMLOCK), KC_PSLS, KC_PAST, KC_PMNS,
        KC_HOME,   KC_UP,   KC_PGUP,   KC_PPLS,
        KC_LEFT,   KC_P5,   KC_RIGHT,   KC_PPLS,
        KC_END,   KC_DOWN,   KC_PGDN,   KC_PENT,
        KC_P0,   KC_DOT,  KC_PDOT, KC_PENT
    ),
    [_WORK] = LAYOUT_ortho_6x4(
        _______, _______, KC_MUTE,  MO(_CONFIG),
        _______, _______, _______, KC_VOLD,
        _______, _______,   _______, KC_VOLU,
        _______, _______, _______, KC_VOLU,
        _______, _______,  _______, _______,
        _______, _______, _______, _______
    ),
    [_CONFIG] = LAYOUT_ortho_6x4(
        _______, RGB_MOD, _______, RGB_TOG,
        RESET, _______, _______, _______,
        _______, BL_ON,   _______, BL_INC,
        _______, BL_TOGG, _______, BL_INC,
        _______, BL_OFF,  _______, BL_DEC,
        BL_BRTG, _______, _______, BL_DEC
    )
};
bool led_update_user(led_t led_state) {
    return false;
}

// Sets pin D0 high or low depending on whether the highest active layer is your fn layer
layer_state_t layer_state_set_user(layer_state_t state) {
    writePin(D0, layer_state_cmp(state, _NUMLOCK));
    return state;
}
