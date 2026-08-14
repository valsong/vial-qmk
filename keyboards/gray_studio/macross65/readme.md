# Gray Studio macross65

# 初始化vial环境并检查

```shell

git submodule update --init --recursive

make git-submodule
qmk doctor
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
