# CMake_examples
Some simple project examples using CMake.

* [hello_world项目实例](https://github.com/suoych/CMake_examples/tree/master/hello_world)
* [hello_world库、安装规则与测试示例](https://github.com/suoych/CMake_examples/tree/master/hello_world_lib)
* [GLOB示例](https://github.com/suoych/CMake_examples/tree/master/GLOB_example)
* [add_custom_command和add_custom_target示例](https://github.com/suoych/CMake_examples/tree/master/add_custom_example)

想尝试某个例子，在对应例子目录下输入以下指令即可：
```bash
mkdir build && cd build
cmake ..
make
```
如果指定了安装规则与测试，则可以：
输入
```bash
make install
```
将编译的结果安装到指定位置。
输入：
```bash
ctest -VV
```
进行测试。
