/* Copyright 2023 Val
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

// keymaps/default/keymap.c

#include QMK_KEYBOARD_H

#define _MAC 0
#define _WIN 1
#define _FN1 2
#define _FN2 3
#define _FN3 4
#define _FN4 5

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_HOME, KC_PGUP,   KC_VOLU,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_END,  KC_PGDN,   KC_VOLD,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,    KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN2),    KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_WIN] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_HOME, KC_PGUP,   KC_VOLU,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_END,  KC_PGDN,   KC_VOLD,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,    KC_UP,
        KC_LCTL, KC_LGUI,  KC_LALT,                            KC_SPC,                             KC_RGUI,  MO(_FN1), MO(_FN2),    KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN1] = LAYOUT(
        KC_TILD, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______,    KC_HOME, KC_PGUP,   _______,
        _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,  _______,  _______,    KC_END,  KC_PGDN,   _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,             _______,
        _______,           _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______,            _______,    KC_UP,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,     KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN2] = LAYOUT(
        KC_GRV,  KC_BRID,  KC_BRIU, KC_NO,   KC_NO,   RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE,  KC_VOLD,  KC_VOLU,    _______,    KC_HOME, KC_PGUP,   _______,
        RGB_TOG, RGB_MOD,  RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______,  _______, _______,   _______,  _______,  _______,    KC_END,  KC_PGDN,   _______,
        _______, RGB_RMOD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______,   _______, _______,  _______,            _______,
        _______,           _______, _______, _______, _______, _______, NK_TOGG, _______, _______, _______, _______,               _______,    KC_UP,
        _______, _______,  _______,                            _______,                            _______,  _______,  _______,     KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN3] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_HOME, KC_PGUP,   _______,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_END,  KC_PGDN,   _______,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,    KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN2),    KC_LEFT, KC_DOWN, KC_RGHT
        ),

    [_FN4] = LAYOUT(
        KC_ESC,  KC_1,     KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,    KC_HOME, KC_PGUP,   _______,
        KC_TAB,  KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,    KC_END,  KC_PGDN,   _______,
        KC_CAPS, KC_A,     KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,            KC_ENT,
        KC_LSFT,           KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_SLSH,            KC_RSFT,    KC_UP,
        KC_LCTL, KC_LOPT,  KC_LCMD,                            KC_SPC,                             KC_RCMD,  MO(_FN1), MO(_FN2),    KC_LEFT, KC_DOWN, KC_RGHT
        )

};

// 滚轮的回调，不要使用encoder_update_user，否则会同时触发KC_VOLU和KC_VOLD以及自定义的按键
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) {
        // Don't process further events if user function exists and returns false
        return false;
    }
    // 当前层级
    uint8_t layer = get_highest_layer(layer_state);
    if (index == 0) {
        if (clockwise) {
            // 滚轮上
            tap_code16(dynamic_keymap_get_keycode(layer, 2, 13));
        } else {
            // 滚轮下
            tap_code16(dynamic_keymap_get_keycode(layer, 3, 13));
        }
    }
    return true;
}
