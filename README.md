# Shudo

代码结构如下：

<img src="C:\Users\华为\AppData\Roaming\Typora\typora-user-images\image-20230630020718196.png" alt="image-20230630020718196" style="zoom: 50%;" />

其中，gtest为googletest测试框架所需文件，include和src中为googletest测试框架的include和src，lib中存放链接库libgtest\_main.dll、libgtest.dll以及单元测试生成的测试可执行文件。

include中存放头文件。

src中存放单元测试源码，主干源码为shudu.cpp，其生成的可执行文件为final_shudu.exe，shudu_unittest.cpp为单元测试代码，生成的结果中，shudu_final.txt为生成的终局、shudu_games.txt为默认生成的初级难度数独谜题、shudu_games2.txt为生成的指定难度数独谜题、shudu_games3.txt为生成的有唯一解的数独谜题，shudu\_result.txt为解题结果。

a-shudu.gcda、hudu.gcno、a.out、shudu.c.gcov和其他gcov文件均为进行覆盖率测试时生成的文件。

主目录下的CMakeLists.txt、CMakeCache.txt文件为单元测试中cmake编译文件，编译完成后生成可执行文件test\_shudu.exe。