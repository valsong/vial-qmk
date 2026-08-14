// Copyright 2022 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0
#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/**延长消除抖动时间**/
#define DEBOUNCE 10

/*
 * WS2812 PWM 驱动配置（替代 bitbang，根治 GCC 版本时序依赖）
 *
 * 背景：原用 bitbang 驱动，其 NOP 循环时序依赖 arm-none-eabi-gcc 的代码生成
 * 行为。ChibiOS 升级到 21.11.x 配套 GCC 15.3.1 后，循环控制指令被优化得更
 * 少，导致 T1H 变短、LED 常亮白色（见原 bitbang 方案的 FUDGE 注释历史）。
 * 现改用 PWM + DMA 硬件产生 WS2812 时序，时序由定时器决定，与编译器无关。
 *
 * 引脚/外设映射（STM32F072 数据手册）：
 *   - WS2812_DI_PIN = PB10 = TIM2_CH3（数据手册与 ChibiOS board.h 一致：
 *     #define GPIOB_TIM2_CH3 10U）
 *   - 使用 PWMD2（TIM2），通道 3
 *   - TIM2 更新事件(TIM2_UP)的 DMA 请求固定映射到 DMA1 通道2
 *     （STM32F072 参考手册 DMA1 通道请求表），无 DMAMUX，硬件固定。
 *   - AF 模式号：F072 下 TIM2 各通道 AF=2（USE_GPIOV1 → PAL_MODE_ALTERNATE(2)）
 *
 * 配套：mcuconf.h 里已 STM32_PWM_USE_TIM2 TRUE。
 * 若回退到 bitbang：删本段 + keyboard.json 的 "driver":"pwm" + mcuconf.h，
 *   并恢复下方的 WS2812_BITBANG_NOP_FUDGE 0.25。
 */
#define WS2812_PWM_DRIVER PWMD2
#define WS2812_PWM_CHANNEL 3
#define WS2812_PWM_PAL_MODE 2
#define WS2812_PWM_DMA_STREAM STM32_DMA1_STREAM2
#define WS2812_PWM_DMA_CHANNEL 2

/*
 * [已废弃] bitbang 时序补偿系数 —— 已改用 PWM 硬件驱动，此配置不再生效。
 * 完整保留作为回退参考与历史记录：若 PWM 方案不可用需回退 bitbang，取消
 * 下面注释，并删掉上方的 PWM 配置 + keyboard.json 的 driver 字段 +
 * mcuconf.h 的 TIM2 开启 + halconf.h 的 HAL_USE_PWM + chconf.h 的 TIMEDELTA=0。
 *   根因：arm-none-eabi-gcc 15.3.1 下 -Os 使 wait_ns 的 for+nop 循环控制开销
 *   变小，默认 0.4 致 T1H≈580ns 低于 WS2812 最低 750ns，LED 常亮白色。
 *   实测 0.25 可把 T1H 拉回约 900ns。
 */
// #define WS2812_BITBANG_NOP_FUDGE 0.25
