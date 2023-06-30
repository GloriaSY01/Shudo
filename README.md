# Shudo

代码结构如下：

```
C:.
│  ALL_BUILD.vcxproj
│  ALL_BUILD.vcxproj.filters
│  CMakeCache.txt
│  CMakeLists.txt
│  cmake_install.cmake
│  CppProperties.json
│  Makefile
│  README.md
│  test_shudu.sln
│  test_shudu.vcxproj
│  test_shudu.vcxproj.filters
│  ZERO_CHECK.vcxproj
│  ZERO_CHECK.vcxproj.filters
│  
├─.vs
│  │  ProjectSettings.json
│  │  slnx.sqlite
│  │  VSWorkspaceState.json
│  │  
│  └─Shudo
│      ├─FileContentIndex
│      │      8ec84612-3e55-402d-9f34-b3b4df1dc387.vsidx
│      │      ff783e51-321a-406c-b834-936296392563.vsidx
│      │      read.lock
│      │      
│      └─v17
│              .suo
│              Browse.VC.db
│              
├─.vscode
│      c_cpp_properties.json
│      settings.json
│      tasks.json
│      
├─CMakeFiles
│  │  cmake.check_cache
│  │  CMakeConfigureLog.yaml
│  │  CMakeDirectoryInformation.cmake
│  │  generate.stamp
│  │  generate.stamp.depend
│  │  generate.stamp.list
│  │  Makefile.cmake
│  │  Makefile2
│  │  progress.marks
│  │  TargetDirectories.txt
│  │  
│  ├─3.27.0-rc3
│  │  │  CMakeCCompiler.cmake
│  │  │  CMakeCXXCompiler.cmake
│  │  │  CMakeDetermineCompilerABI_C.bin
│  │  │  CMakeDetermineCompilerABI_CXX.bin
│  │  │  CMakeRCCompiler.cmake
│  │  │  CMakeSystem.cmake
│  │  │  
│  │  ├─CompilerIdC
│  │  │      a.exe
│  │  │      CMakeCCompilerId.c
│  │  │      
│  │  └─CompilerIdCXX
│  │          a.exe
│  │          CMakeCXXCompilerId.cpp
│  │          
│  ├─ccca9885d6bae499929f0b9d77a39c75
│  │      generate.stamp.rule
│  │      
│  ├─sample1.dir
│  │  │  build.make
│  │  │  cmake_clean.cmake
│  │  │  compiler_depend.internal
│  │  │  compiler_depend.make
│  │  │  compiler_depend.ts
│  │  │  depend.make
│  │  │  DependInfo.cmake
│  │  │  flags.make
│  │  │  includes_CXX.rsp
│  │  │  link.d
│  │  │  link.txt
│  │  │  linkLibs.rsp
│  │  │  objects.a
│  │  │  objects1.rsp
│  │  │  progress.make
│  │  │  
│  │  └─src
│  │          sample1.cc.obj
│  │          sample1.cc.obj.d
│  │          sample1_unittest.cc.obj
│  │          sample1_unittest.cc.obj.d
│  │          
│  └─test_shudu.dir
│      │  build.make
│      │  cmake_clean.cmake
│      │  compiler_depend.internal
│      │  compiler_depend.make
│      │  compiler_depend.ts
│      │  depend.make
│      │  DependInfo.cmake
│      │  flags.make
│      │  includes_CXX.rsp
│      │  link.d
│      │  link.txt
│      │  linkLibs.rsp
│      │  objects.a
│      │  objects1.rsp
│      │  progress.make
│      │  
│      └─src
│              shudu.cpp.gcda
│              shudu.cpp.gcno
│              shudu.cpp.obj
│              shudu.cpp.obj.d
│              shudu_unittest.cpp.gcda
│              shudu_unittest.cpp.gcno
│              shudu_unittest.cpp.obj
│              shudu_unittest.cpp.obj.d
│              
├─gtest
│  ├─include
│  │  └─gtest
│  │      │  gtest-death-test.h
│  │      │  gtest-matchers.h
│  │      │  gtest-message.h
│  │      │  gtest-param-test.h
│  │      │  gtest-printers.h
│  │      │  gtest-spi.h
│  │      │  gtest-test-part.h
│  │      │  gtest-typed-test.h
│  │      │  gtest.h
│  │      │  gtest_pred_impl.h
│  │      │  gtest_prod.h
│  │      │  
│  │      └─internal
│  │          │  gtest-death-test-internal.h
│  │          │  gtest-filepath.h
│  │          │  gtest-internal.h
│  │          │  gtest-param-util.h
│  │          │  gtest-port-arch.h
│  │          │  gtest-port.h
│  │          │  gtest-string.h
│  │          │  gtest-type-util.h
│  │          │  
│  │          └─custom
│  │                  gtest-port.h
│  │                  gtest-printers.h
│  │                  gtest.h
│  │                  README.md
│  │                  
│  ├─lib
│  │      libgtest.dll
│  │      libgtest_main.dll
│  │      questions.txt
│  │      shudu_final.txt
│  │      shudu_result.txt
│  │      test_shudu.exe
│  │      
│  └─src
│          gtest-all.cc
│          gtest-death-test.cc
│          gtest-filepath.cc
│          gtest-internal-inl.h
│          gtest-matchers.cc
│          gtest-port.cc
│          gtest-printers.cc
│          gtest-test-part.cc
│          gtest-typed-test.cc
│          gtest.cc
│          gtest_main.cc
│          
├─include
│      sample1.h
│      shudu.h
│      
└─src
        a-shudu.gcda
        a-shudu.gcno
        a.out
        allocator.h.gcov
        alloc_traits.h.gcov
        basic_string.h.gcov
        basic_string.tcc.gcov
        char_traits.h.gcov
        cpp_type_traits.h.gcov
        final_shudu.exe
        limits.gcov
        move.h.gcov
        new.gcov
        new_allocator.h.gcov
        predefined_ops.h.gcov
        questions.txt
        random.h.gcov
        random.tcc.gcov
        sample1.cc
        sample1_unittest.cc
        shudu
        shudu.cpp
        shudu.cpp.gcov
        shudu.exe
        shudu_final.txt
        shudu_games.txt
        shudu_games2.txt
        shudu_games3.txt
        shudu_result.txt
        shudu_unittest.cpp
        stdio.h.gcov
        stl_algo.h.gcov
        stl_algobase.h.gcov
        stl_construct.h.gcov
        stl_heap.h.gcov
        stl_iterator.h.gcov
        stl_iterator_base_funcs.h.gcov
        stl_iterator_base_types.h.gcov
        stl_pair.h.gcov
        stl_uninitialized.h.gcov
        stl_vector.h.gcov
        string_conversions.h.gcov
        type_traits.h.gcov
        uniform_int_dist.h.gcov
        vector.tcc.gcov
        

```

其中，gtest为googletest测试框架所需文件，include和src中为googletest测试框架的include和src，lib中存放链接库libgtest\_main.dll、libgtest.dll以及单元测试生成的测试可执行文件。

include中存放头文件。

src中存放单元测试源码，主干源码为shudu.cpp，其生成的可执行文件为final_shudu.exe，shudu_unittest.cpp为单元测试代码，生成的结果中，shudu_final.txt为生成的终局、shudu_games.txt为默认生成的初级难度数独谜题、shudu_games2.txt为生成的指定难度数独谜题、shudu_games3.txt为生成的有唯一解的数独谜题，shudu\_result.txt为解题结果。

a-shudu.gcda、hudu.gcno、a.out、shudu.c.gcov和其他gcov文件均为进行覆盖率测试时生成的文件。

主目录下的CMakeLists.txt、CMakeCache.txt文件为单元测试中cmake编译文件，编译完成后生成可执行文件test\_shudu.exe。