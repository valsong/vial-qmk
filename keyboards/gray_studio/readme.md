# Gray Studio


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

```
Compiling: .build/obj_gray_studio_macross65_vialv/src/default_keyboard.c                           dyld[32179]: Library not loaded: /opt/homebrew/opt/isl/lib/libisl.23.dylib
  Referenced from: <E4328ABF-E1CF-3A31-99E5-DBA615BA4D23> /opt/homebrew/Cellar/arm-none-eabi-gcc@8/8.5.0_2/libexec/gcc/arm-none-eabi/8.5.0/cc1
  Reason: tried: '/opt/homebrew/opt/isl/lib/libisl.23.dylib' (no such file), '/System/Volumes/Preboot/Cryptexes/OS/opt/homebrew/opt/isl/lib/libisl.23.dylib' (no such file), '/opt/homebrew/opt/isl/lib/libisl.23.dylib' (no such file)
arm-none-eabi-gcc: internal compiler error: Abort trap: 6 signal terminated program cc1
Please submit a full bug report,
with preprocessed source if appropriate.
See <https://github.com/osx-cross/homebrew-arm/issues> for instructions.
 [ERRORS]
 | 
 | 
 | 
make: *** [.build/obj_gray_studio_macross65_vialv/.build/obj_gray_studio_macross65_vialv/src/default_keyboard.o] Error 1

```

## 解决方案
```shell
brew remove arm-none-eabi-gcc
rm  -rf /opt/homebrew/bin/arm-none-eabi*
brew install --cask gcc-arm-embedded
```

参考  

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
