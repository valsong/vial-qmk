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
