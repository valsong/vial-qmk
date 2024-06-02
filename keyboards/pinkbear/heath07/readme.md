
# 刷固件的方法

拔下左下角的L_ALT按键，使用镊子链接两个焊盘两次，达到双击的效果。
这时候电脑出现一个U盘，将XXX.uf2文件拖入即可


# STM32F103xB_uf2.ld
编译固件的时候，注意要将STM32F103xB_uf2.ld放到以下的目录中
```shell
qmk_firmware/platforms/chibios/boards/common/ld/STM32F103xB_uf2.ld
```



# 参考教程
[F103及国产兼容芯片构建QMK固件](https://www.zfrontier.com/app/flow/eMzZjJZRgP6z)


# macos编译报错
M1芯片的MacOs编译STM32F103xB的固件时候会报错
```
➜  qmk_firmware git:(master) make sowbug/68keys:default
QMK Firmware 0.22.14
Making sowbug/68keys with keymap default

Generating: .build/obj_sowbug_68keys_default/src/info_deps.d                                        [OK]
arm-none-eabi-gcc (GCC) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

Generating: .build/obj_sowbug_68keys_default/src/info_config.h                                     ^[ [OK]
Generating: .build/obj_sowbug_68keys_default/src/default_keyboard.c                                 [OK]
Generating: .build/obj_sowbug_68keys_default/src/default_keyboard.h                                 [OK]
Compiling: keyboards/sowbug/68keys/68keys.c                                                        In file included from ./lib/chibios/os/hal/osal/rt-nil/osal.h:29,
                 from ./lib/chibios/os/hal/include/hal.h:30,
                 from ./platforms/chibios/drivers/wear_leveling/wear_leveling_efl_config.h:6,
                 from <command-line>:
/opt/homebrew/Cellar/arm-none-eabi-gcc/13.2.0/lib/gcc/arm-none-eabi/13.2.0/include/stdint.h:9:16: fatal error: stdint.h: No such file or directory
    9 | # include_next <stdint.h>
      |                ^~~~~~~~~~
compilation terminated.
 [ERRORS]
 |
 |
 |
make[1]: *** [.build/obj_sowbug_68keys_default/keyboards/sowbug/68keys/68keys.o] Error 1
make: *** [sowbug/68keys:default] Error 1
Make finished with errors

```

## 解决方案
```shell
brew remove arm-none-eabi-gcc
rm  -rf /opt/homebrew/bin/arm-none-eabi*
brew install --cask gcc-arm-embedded
```




# 参考  

>Do not install it with
>```shell
>brew install arm-none-eabi-xxx
>```
>
>Use
>```shell
>brew install --cask gcc-arm-embedded
>```
>to install the whole toolchain.
>
>Uninstall the first installation before use the second one.


# 初始化vial环境并检查

```shell
make git-submodule
qmk doctor
```

# 编译固件的方式
```shell
make pinkbear/heath07:vial
qmk compile -kb pinkbear/heath07 -km vial
```

```shell
make pinkbear/heath07:vialv
qmk compile -kb pinkbear/heath07 -km vialv
```

# note
刷入utf2文件后，键盘无法识别   
只能重新刷回via固件
