# Gray Studio bd60

 A 60% keyboard by Graystudio. PCB designed and manufactured by DEMO Studio.

 * Keyboard Maintainer: [edwardslau](https://github.com/edwardslau)
 * Hardware Support: bd60
 * Hardware Availability:

 Make example for this keyboard (after setting up your build environment):

 	make gray_studio bd60:default

 Flashing example for this keyboard:

 	make gray_studio bd60:default:flash

## Bootloader

* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead

See the [build environment setup](https://docs.qmk.fm/#/getting_started_build_tools) and the [make instructions](https://docs.qmk.fm/#/getting_started_make_guide) for more infromation. Brand new to QMK? Start with our [Complete Newbs Guide](https://docs.qmk.fm/#/newbs).


# 初始化vial环境并检查  

```shell
make git-submodule
qmk doctor
```

# 编译固件  

```shell
make gray_studio/bd60:vialv
```

```shell
qmk compile -kb gray_studio/bd60 -km vialv
```

# 刷新固件

```shell
make gray_studio/bd60:vialv:flash
```

```shell
qmk flash -kb gray_studio/bd60 -km vialv
```

