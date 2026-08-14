# Gray Studio macross65

# 初始化vial环境并检查

```shell
git submodule update --init --recursive

make git-submodule
qmk doctor
```


# git submodule依赖出现问题时 

```shell 
# 1. 重置所有子模块，丢弃本地修改
git submodule foreach --recursive git reset --hard
# 2. 清理所有子模块中未跟踪的文件和目录
git submodule foreach --recursive git clean -ffdx
# 3. 最后，再执行一次干净的更新
git submodule update --init --recursive --force
```

# 编译固件
```shell
make gray_studio/macross65:vialv
```

```shell
qmk compile -kb gray_studio/macross65 -km vialv
```

# 刷新固件

```shell
make gray_studio/macross65:vialv:flash
```

```shell
qmk flash -kb gray_studio/macross65 -km vialv
```


# 错误
```
sh: dfu-suffix: command not found
make: *** [.build/gray_studio_macross65_vialv.bin] Error 127
```
## 解决方案
```shell
brew install dfu-util
```


# 消除抖动 
keyboard.json  
```
   "build": {
        "debounce_type": "sym_defer_pk"
    },
```
config.h  
```
/**延长消除抖动时间**/
#define DEBOUNCE 10
```

# WS2812 RGB 驱动（PWM 硬件驱动）

## 背景

原使用 bitbang 驱动，其 NOP 循环时序依赖 `arm-none-eabi-gcc` 的代码生成行为。
ChibiOS 升级到 21.11.x 配套 GCC 15.3.1 后，`-Os` 优化使 `wait_ns` 宏里
`for` 循环控制指令开销变小，导致 T1H≈580ns 低于 WS2812 协议最低 750ns，
LED 无法识别 "1" 位，表现为常亮白色、无法调节。原方案用 `WS2812_BITBANG_NOP_FUDGE 0.25`
补偿（见 config.h 已废弃注释），但每次升级 GCC 工具链都要重新实测微调。

现改用 **PWM + DMA 硬件驱动**，时序由 STM32 硬件定时器产生，与编译器版本彻底解耦，
升级 ChibiOS/GCC 不再需要动 RGB 配置。

## 硬件映射（STM32F072）

- WS2812 数据脚 `PB10 = TIM2_CH3`（数据手册与 ChibiOS `board.h` 一致）
- 使用 `PWMD2`（TIM2），通道 3，AF 模式号 2
- TIM2 更新事件 DMA 请求固定映射到 DMA1 通道2（F072 无 DMAMUX，硬件固定）

## 配置文件

| 文件 | 作用 |
|------|------|
| `keyboard.json` | `ws2812.driver = "pwm"` |
| `config.h` | PWM 驱动参数（PWMD2/CH3/AF2/DMA1_STREAM2/CH2） |
| `mcuconf.h` | `STM32_PWM_USE_TIM2 TRUE` |
| `halconf.h` | `HAL_USE_PWM TRUE` |
| `chconf.h` | `CH_CFG_ST_TIMEDELTA 0`（见下） |

## 关键：释放 TIM2

F072 默认系统时基走 TIM2（`STM32_ST_USE_TIMER=2`），与 WS2812 PWM 抢占 TIM2
会报 `#error "ST requires TIM2 but the timer is already used"`。
故在 `chconf.h` 设 `CH_CFG_ST_TIMEDELTA 0`，关闭 tickless 模式，
系统时基改用 ARM 硬件 SysTick（PERIODIC 模式），TIM2 完全释放给 PWM。
代价：idle 线程无法进入 tickless 深睡，功耗略增；实测打字/动画/USB 均正常。
参考 `STM32_F103_STM32DUINO` / `GENERIC_WB32` 同样使用 `TIMEDELTA=0`。

## 回退到 bitbang

若 PWM 方案不可用需回退 bitbang，依次：
1. `keyboard.json` 删 `ws2812.driver`
2. `config.h` 删 PWM 配置段，取消注释 `WS2812_BITBANG_NOP_FUDGE 0.25`
3. 删 `mcuconf.h` / `halconf.h`
4. `chconf.h` 删 `CH_CFG_ST_TIMEDELTA 0`

