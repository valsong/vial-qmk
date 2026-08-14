// Copyright 2024 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0

#pragma once

#include_next <mcuconf.h>

/*
 * 开启 TIM2 供 WS2812 PWM 驱动使用。
 *
 * 背景：PB10 = TIM2_CH3 是 WS2812 数据脚唯一可用的 PWM 通道。
 * 默认 GENERIC_STM32_F072XB 的 STM32_PWM_USE_TIM2 为 FALSE，需在此打开。
 *
 * TIM2 占用冲突已解决：F072 默认系统时基走 TIM2（STM32_ST_USE_TIMER=2），
 * 与 PWM 抢占。现已在 chconf.h 设 CH_CFG_ST_TIMEDELTA=0，切到 PERIODIC 模式，
 * 系统时基改用 ARM 硬件 SysTick，TIM2 完全释放给 PWM，无需再改 ST_USE_TIMER。
 */
#undef STM32_PWM_USE_TIM2
#define STM32_PWM_USE_TIM2 TRUE
