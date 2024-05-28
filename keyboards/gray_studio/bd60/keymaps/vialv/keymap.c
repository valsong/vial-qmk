// Copyright 2023 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_ESC,        KC_1,         KC_2,        KC_3,        KC_4,        KC_5,        KC_6,        KC_7,        KC_8,       KC_9,        KC_0,        KC_MINS,      KC_EQL,      KC_BSPC,     KC_NO,
        LT(3,KC_TAB),  KC_Q,         KC_W,        KC_E,        KC_R,        KC_T,        KC_Y,        KC_U,        KC_I,       KC_O,        KC_P,        KC_LBRC,      KC_RBRC,     KC_BSLS,
        KC_LCTL,       KC_A,         KC_S,        KC_D,        KC_F,        KC_G,        KC_H,        KC_J,        KC_K,       KC_L,        KC_SCLN,     KC_QUOT,                   KC_ENT,
        KC_LSFT,                     KC_Z,        KC_X,        KC_C,        KC_V,        KC_B,        KC_N,        KC_M,       KC_COMM,     KC_DOT,      KC_SLSH,                   KC_RSFT,     KC_NO,
        MO(1),         KC_LALT,      KC_LGUI,                               KC_SPC,                                                         KC_RGUI,     MO(1),        MO(2),       MO(1)
    ),

    [1] = LAYOUT(
        KC_GRV,        KC_F1,        KC_F2,       KC_F3,       KC_F4,       KC_F5,       KC_F6,       KC_F7,       KC_F8,      KC_F9,       KC_F10,       KC_F11,      KC_F12,      KC_DEL,      KC_NO,
        S(KC_GRV),     _______,      KC_UP,       _______,     G(KC_SPC),   _______,     KC_INS,      KC_BSPC,     KC_DEL,     KC_ENT,      KC_PGUP,      KC_ESC,      _______,     _______,
        _______,       KC_LEFT,      KC_DOWN,     KC_RIGHT,    _______,     _______,     KC_LEFT,     KC_DOWN,     KC_UP,      KC_RGHT,     KC_PGDN,      KC_END,                   _______,
        _______,                     _______,     _______,     _______,     _______,     _______,     KC_HOME,     KC_PGDN,    KC_PGUP,     KC_END,       KC_UP,                    _______,     KC_NO,
        _______,       _______,      _______,                               _______,                                                        KC_LEFT,      KC_DOWN,     KC_RIGHT,    _______
    ),

    [2] = LAYOUT(
        _______,       KC_BRID,      KC_BRIU,     KC_NO,       KC_NO,       RGB_VAD,     RGB_VAI,     KC_MPRV,     KC_MPLY,     KC_MNXT,    KC_MUTE,      KC_VOLD,      KC_VOLU,    LCA(KC_DEL), KC_NO,
        RGB_TOG,       _______,      _______,     _______,     _______,     _______,     _______,     _______,     _______,     _______,    _______,      TO(4),        TO(3),      TO(0),
        KC_CAPS,       RGB_MOD,      RGB_HUI,     RGB_SAI,     RGB_VAI,     RGB_SPI,     _______,     _______,     _______,     _______,    _______,      _______,                  _______,
        MAGIC_NO_GUI,                RGB_RMOD,    RGB_HUD,     RGB_SAD,     RGB_VAD,     RGB_SPD,     NK_TOGG,     _______,     _______,    _______,      _______,                  _______,     KC_NO,
        MAGIC_SWAP_LALT_LGUI,MAGIC_UNNO_GUI,MAGIC_UNSWAP_LALT_LGUI,         _______,                                                        _______,      _______,      _______,    _______
        ),

    [3] = LAYOUT(
        TO(0),         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      _______,     _______,
        _______,       KC_NO,        KC_MS_UP,    KC_NO,       KC_NO,       KC_NO,       KC_MS_WH_LEFT,KC_MS_WH_DOWN,KC_MS_WH_UP,KC_MS_WH_RIGHT,KC_MS_ACCEL2,KC_NO,     KC_NO,      _______,
        _______,       KC_MS_LEFT,   KC_MS_DOWN,  KC_MS_RIGHT, KC_NO,       KC_NO,       KC_MS_BTN3,  KC_MS_BTN1,  KC_MS_BTN2,  KC_MS_ACCEL0,KC_MS_ACCEL1,KC_MS_ACCEL2,             _______,
        _______,                     KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,                    _______,     _______,
        _______,       _______,      _______,                               _______,                                                        _______,      _______,      _______,    _______
        ),

    [4] = LAYOUT(
        TO(0),         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_NO,       KC_NO,
        KC_NO,         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,        KC_NO,      KC_NO,
        KC_NO,         KC_NO,        KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,                    KC_NO,
        KC_NO,                       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,       KC_NO,      KC_NO,        KC_NO,                    KC_NO,       KC_NO,
        KC_NO,         KC_NO,        KC_NO,                                 KC_NO,                                                          KC_NO,        KC_NO,        KC_NO,      KC_NO
        ),

};
