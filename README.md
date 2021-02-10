## What is this
Personal ShuaTi notes and some useful ShuaTi Tools

## How to use
Copy and paste,  add plezzle solutions class file to `problem/` 
```cpp

#include "../leet_data.h"
#include "../leet_tool.h"
#include <iostream>
using namespace leet;
using namespace std;

class Solution {
    /*
    *  define your solution here
    */
}

int main() {

    cout << "Hello, World" << endl;
    return 0;
}

```

## 用VScode 搭建c++11 开发环境

### 安装C/C++ 插件
只需要安装下面两个插件即可：

* C/C++
* C/C++ Clang Command Adapter

配置编译task，task.json
在当前文件是C++的情况下，编译选项的配置是放在 `.vscode/tasks.json` 里，主要用来告诉VS Code如何Compile/Build 程序
> 注： 如果要使用C++ 11, 则需要增加 "-std=c++11"、"-stdlib=libc++" 这两个选项

如何执行编译好的文件, 配置 launch.json
`.vscode/launch.json` 文件告诉VS Code 如何运行编译好的文件
> 注意： tasks.json的"label"参数值和launch.json的"preLaunchTask"参数值必须一致，否则可能报“launch：program "xxxx" does not exist”

运行程序
点击 Run ->Start Debugging 即可开始调试任务

### Enable C++11
点击Code->Preferences->Settings， 搜索Clang: Cflags、Clang: Cxxflags增加C++11 的配置即可

* Clang: Cflags增加Item： "-std=c11"
* Clang: Cxxflags增加Item： "-std=c++11"
