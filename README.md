# Features Project

这是一个基础的C++项目模板。

## 项目结构

```
Features/
├── src/              # 源文件目录
├── include/          # 头文件目录
├── build/            # 构建输出目录
├── CMakeLists.txt    # CMake 配置文件
├── .gitignore        # Git 忽略文件
└── README.md         # 项目说明
```

## 编译步骤

### 使用 CMake 编译

1. 创建构建目录并进入：
```bash
cd build
```

2. 运行 CMake 配置：
```bash
cmake ..
```

3. 编译项目：
```bash
cmake --build .
```

或者直接使用：
```bash
make
```

### 运行程序

编译完成后，在 build 目录中运行可执行文件：
```bash
./Features
```

## 要求

- C++17 或更高版本
- CMake 3.10 或更高版本

## 开发建议

- 在 `src/` 目录下添加源文件
- 在 `include/` 目录下添加头文件
- 更新 `CMakeLists.txt` 以添加新的源文件
