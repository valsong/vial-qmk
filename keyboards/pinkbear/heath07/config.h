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

#pragma once

#define WS2812_PWM_DRIVER   PWMD4

#define WS2812_PWM_CHANNEL  4

#define WS2812_PWM_PAL_MODE 2

// DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_STREAM   STM32_DMA1_STREAM6

// DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_DMA_CHANNEL  2

#define WS2812_PWM_TARGET_PERIOD 800000

// 滚轮
#define ENCODERS_PAD_A { A7 }
#define ENCODERS_PAD_B { B0 }
#define ENCODER_RESOLUTION 4

// 键盘四周灯条
#ifdef RGBLIGHT_ENABLE

    #undef RGBLED_NUM
    #define RGBLIGHT_SLEEP

    #define RGBLIGHT_EFFECT_BREATHING
    #define RGBLIGHT_EFFECT_RAINBOW_MOOD
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    #define RGBLIGHT_EFFECT_SNAKE
    #define RGBLIGHT_EFFECT_KNIGHT
    #define RGBLIGHT_EFFECT_CHRISTMAS
    #define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_EFFECT_RGB_TEST
    #define RGBLIGHT_EFFECT_ALTERNATING
    #define RGBLIGHT_EFFECT_TWINKLE

    #define RGBLED_NUM 28
    #define RGBLIGHT_LIMIT_VAL 255
    // The number of steps to increment the saturation by (default 17)
    #define RGBLIGHT_SAT_STEP 17
    // The number of steps to increment the brightness by (default 17)
    #define RGBLIGHT_VAL_STEP 17

#endif
