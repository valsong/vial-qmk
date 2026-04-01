// Copyright 2022 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     [0] = LAYOUT(
        KC_ESC,        KC_1,         KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,       KC_9,        KC_0,        KC_MINS,      KC_EQL,      KC_BSPC,_______,        KC_DEL,
        KC_TAB,        KC_Q,         KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,       KC_O,        KC_P,        KC_LBRC,      KC_RBRC,     KC_BSLS,                KC_PGUP,
        KC_LCTL,       KC_A,         KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,       KC_L,        KC_SCLN,     KC_QUOT,                   KC_ENT,                 KC_PGDN,
        KC_LSFT,       _______,      KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,       KC_COMM,     KC_DOT,      KC_SLSH,      KC_RSFT,     KC_UP,                  MO(2),
        MO(1),         KC_LALT,      KC_LGUI,                               KC_SPC,                                                         KC_RGUI,     MO(1),        KC_LEFT,     KC_DOWN,                KC_RGHT
    ),

     [1] = LAYOUT(
        KC_GRV,        KC_F1,        KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,      KC_F9,       KC_F10,       KC_F11,      KC_F12,      KC_DEL,_______,         KC_TRNS,
        S(KC_GRV),     KC_TRNS,      KC_UP,       KC_TRNS,     G(KC_SPC),   KC_TRNS,     KC_INS,      KC_BSPC,     KC_DEL,     KC_ENT,      KC_PGUP,      KC_ESC,      KC_TRNS,     KC_TRNS,                KC_TRNS,
        KC_TRNS,       KC_LEFT,      KC_DOWN,     KC_RIGHT,    KC_TRNS,     KC_TRNS,     KC_LEFT,     KC_DOWN,     KC_UP,      KC_RGHT,     KC_PGDN,      KC_END,                   KC_TRNS,                KC_TRNS,
        KC_TRNS,       _______,      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_HOME,     KC_PGDN,    KC_PGUP,     KC_END,       KC_TRNS,     KC_TRNS,     KC_UP,                  KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,                               KC_TRNS,                                                        KC_RGUI,      KC_TRNS,     KC_LEFT,     KC_DOWN,                KC_RGHT
    ),

     [2] = LAYOUT(
        TO(0),         KC_BRID,      KC_BRIU,     KC_NO,       KC_NO,       UG_VALD,     UG_VALU,     KC_MPRV,     KC_MPLY,     KC_MNXT,    KC_MUTE,      KC_VOLD,      KC_VOLU,    LCA(KC_DEL),_______,    KC_TRNS,
        UG_TOGG,       KC_TRNS,      KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,      TO(3),      TO(4),                  KC_TRNS,
        KC_CAPS,       UG_NEXT,      UG_HUEU,     UG_SATU,     UG_VALU,     UG_SPDU,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,    KC_TRNS,      KC_TRNS,                  KC_TRNS,                KC_TRNS,
        GU_ON,         _______,      UG_PREV,     UG_HUED,     UG_SATD,     UG_VALD,     UG_SPDD,     NK_ON,       NK_OFF,      KC_TRNS,    KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS,
        AG_LNRM,       GU_OFF,       AG_LSWP,                               KC_TRNS,                                                        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS
        ),

     [3] = LAYOUT(
        TO(0),         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_TRNS,_______,        KC_TRNS,
        KC_TRNS,       KC_NO,        MS_UP,       KC_NO,       KC_NO,       KC_NO,       MS_WHLL,     MS_WHLD,     MS_WHLU,     MS_WHLR,    MS_ACL2,      KC_NO,        KC_NO,      KC_TRNS,                KC_TRNS,
        KC_TRNS,       MS_LEFT,      MS_DOWN,     MS_RGHT,     KC_NO,       KC_NO,       MS_BTN3,     MS_BTN1,     MS_BTN2,     MS_ACL0,    MS_ACL1,      MS_ACL2,                  KC_TRNS,                KC_TRNS,
        KC_TRNS,       _______,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_TRNS,    KC_TRNS,                KC_TRNS,
        KC_TRNS,       KC_TRNS,      KC_TRNS,                               KC_TRNS,                                                        KC_TRNS,      KC_TRNS,      KC_TRNS,    KC_TRNS,                KC_TRNS
        ),

     [4] = LAYOUT(
        TO(0),         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_NO,_______,          KC_NO,
        KC_NO,         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_NO,                  KC_NO,
        KC_NO,         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,                    KC_NO,                  KC_NO,
        KC_NO,         _______,      KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_NO,                  KC_NO,
        KC_NO,         KC_NO,        KC_NO,                                 KC_NO,                                                          KC_NO,        KC_NO,        KC_NO,      KC_NO,                  KC_NO
        )

};

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_WHITE}
);
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
