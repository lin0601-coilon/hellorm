# class_03 机器人标记配置管理器

## 文件职责

 `include/MarkerManager.hpp`：Marker 结构体与 MarkerManager 类的声明。
 `src/MarkerManager.cpp`：MarkerManager 成员函数实现。
 `main.cpp`：演示程序，包含基础题 1~3 的样例数据和结果展示。
 `CMakeLists.txt`：CMake 构建脚本，生成可执行程序 class_03。
 `README.md`：本文件。

## 构建与运行

在工程根目录执行：

```bash
cmake -S . -B build
cmake --build build
./build/class_03

## 检查数据

- 添加编号10，位置(50,50)，优先级100 → 成功
- 添加编号11，位置(-30,-70)，优先级20 → 成功
- 添加编号12，位置(0,0)，优先级75 → 成功
- 重复添加编号10 → 失败
- 添加优先级101的记录 → 失败
- 阈值80统计 → 1
- 阈值50统计 → 2
- 空管理器统计 → 0

##课堂反馈

这节课堂明显感觉吃力了一些 还有作业布置 有的题干读了很多遍才大概理解

##AI使用情况

使用情况增加 学的东西多了 有一些忘记的都要再问ai他的用途 同时很多无法想到处理方法的地方也请教ai
然后写完自己和ai都核对一遍。

