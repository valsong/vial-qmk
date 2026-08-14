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
  1. 新版 ChibiOS（从 q3-8 升级到 q3-533）的编译器优化或调度器行为发生了变化，导致 NOP 循环执行速度比旧版快了
  2. NOP_FUDGE = 0.4 这个补偿系数没有跟着更新，它控制的是 bitbang 时序里每个"等待 1ns"对应多少个 NOP 循环
  3. 结果导致 T1H（表示"1"的高电平时间）只有约 580ns，低于 WS2812 协议要求的最小值 750ns
  4. WS2812 无法正确识别"1"位，所有 bit 都被当成"0"解析，LED 显示的是上次保存的状态——也就是白色
  5. 把 T1H 拉回到约 900ns，满足 WS2812 协议。
  有些ChibiOS版本需要放开
 */
 // #define WS2812_BITBANG_NOP_FUDGE 0.25
