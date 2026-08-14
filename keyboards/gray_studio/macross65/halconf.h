// Copyright 2024 Yizhen Liu (@edwardslau)
// SPDX-License-Identifier: GPL-2.0

#pragma once

/*
 * 开启 PWM HAL 模块，供 WS2812 PWM 驱动使用。
 * 默认 GENERIC_STM32_F072XB 未开启 HAL_USE_PWM，导致 PWMD2/pwmStart 等符号
 * 未定义。必须先于 include_next 定义，让 hal.mk 据此编译 PWM HAL。
 */
#define HAL_USE_PWM TRUE

#include_next <halconf.h>
