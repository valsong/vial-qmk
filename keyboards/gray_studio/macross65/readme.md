# Gray Studio macross65

# 初始化vial环境并检查

```shell
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
