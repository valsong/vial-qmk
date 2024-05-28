# Gray Studio Space65 R3

A 65% keyboard by Graystudio. PCB designed and manufactured by DEMO Studio.

* Keyboard Maintainer: [edwardslau](https://github.com/edwardslau)
* Hardware Supported: Space65 R3
* Hardware Availability: [Graystudio.club](https://graystudio.club/products/gb-space60-%E2%85%B2)

Make example for this keyboard (after setting up your build environment):

    make gray_studio space65r3:default

Flashing example for this keyboard:

    make gray_studio space65r3:default:flash

## Bootloader
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more information. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


# space65r3官方给的代码代码
keyboards/gray_studio/space65r3/keymaps/resource/space65r3 VIAL.zip

# 初始化vial环境并检查

```shell
make git-submodule
qmk doctor
```

# 编译固件
```shell
make gray_studio/space65r3:vialv
```

```shell
qmk compile -kb gray_studio/space65r3 -km vialv
```

# 刷新固件

```shell
make gray_studio/space65r3:vialv:flash
```

```shell
qmk flash -kb gray_studio/space65r3 -km vialv
```
