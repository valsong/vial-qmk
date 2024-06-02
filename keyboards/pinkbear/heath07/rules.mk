# Build Options
#   change yes to no to disable
#

# Enable Bootmagic Lite
BOOTMAGIC_ENABLE = yes
# Mouse keys
MOUSEKEY_ENABLE = yes
# Audio control and System control
EXTRAKEY_ENABLE = yes
# Console for debug
CONSOLE_ENABLE = no
# Commands for debug and configuration
COMMAND_ENABLE = no
# Enable N-Key Rollover
NKRO_ENABLE = yes
# Enable keyboard backlight functionality
BACKLIGHT_ENABLE = no
# Disable RGB key matrix
RGB_MATRIX_ENABLE = no
# Enable keyboard RGB underglow
RGBLIGHT_ENABLE = yes
# Audio output
AUDIO_ENABLE = no

DIP_SWITCH_ENABLE = no

# 代码优化
LTO_ENABLE = yes

# 滚轮
ENCODER_ENABLE = yes

# 蓝牙
BLUETOOTH_ENABLE = no

# MCU name
MCU = STM32F103
MCU_LDSCRIPT = STM32F103xB_uf2
FIRMWARE_FORMAT = uf2
BOARD = STM32_F103_STM32DUINO
# Bootloader selection
BOOTLOADER = custom

OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
