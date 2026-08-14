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
 * WS2812 bitbang 时序补偿系数（已实测验证）
 *
 * 背景：bitbang 驱动用一个 NOP 循环来产生 WS2812 所需的纳秒级时序，
 * FUDGE 用于把"循环计数"换算成真实纳秒，默认值 0.4（仅对 STM32F0/F1/F3/F4
 * 等系列自动生效，见 platforms/chibios/drivers/ws2812_bitbang.c）。
 *
 * 问题：本键盘 MCU 为 STM32F072，在 ChibiOS 21.11.x（由旧版 q3-8 升级到 q3-533）
 * 下，编译器优化与调度器行为变化使 NOP 循环执行变快，默认 0.4 会让：
 *   T1H（表示 "1" 的高电平）≈ 580ns，低于 WS2812 协议最低值 750ns。
 * 结果 LED 无法正确识别 "1" 位，所有 bit 被当 "0" 解析，表现为常亮白色、
 * 无法调节、无法关闭。
 *
 * 实测：0.4 复现上述白色故障；0.25 可把 T1H 拉回约 900ns，恢复正常。
 *
 * 维护提示：
 *   - 这是与 ChibiOS 版本/工具链相关的时序 hack，升级 ChibiOS 后需重新实测，
 *     优先尝试删除本行回落默认 0.4，灯效正常则可删；异常则保留并微调。
 *   - 仅在 bitbang 驱动下生效，若改用 SPI/PWM 等其他 WS2812 驱动应移除。
 */
#define WS2812_BITBANG_NOP_FUDGE 0.25
