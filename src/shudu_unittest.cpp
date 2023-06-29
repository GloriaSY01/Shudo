#include <gtest/gtest.h>
#include <fstream>
#include "..\include\shudu.h"
// 定义测试套件
class SudokuTest : public ::testing::Test {
protected:
  // 在每个测试用例执行前运行
  void SetUp() override {
    // 创建一个测试用例前的准备工作
  }

  // 在每个测试用例执行后运行
  void TearDown() override {
    // 清理工作，确保每个测试用例都是独立的
  }
};

// 测试生成数独终局的函数
TEST_F(SudokuTest, TestProduceOutputIntoTxt) {
  int produce_num = 10;
  int result = produceOutputIntoTxt(produce_num);
  
  // 验证函数的返回值是否符合预期
  EXPECT_EQ(result, 0);

  // 验证生成的数独终局文件是否存在
  std::ifstream file("./shudu_final.txt");
  EXPECT_TRUE(file.good());
}

// 测试处理数独问题的函数
TEST_F(SudokuTest, TestDealQuestion) {
  char* path = "path_to_question_file.txt";
  int result = dealQuestion(path);

  // 验证函数的返回值是否符合预期
  EXPECT_EQ(result, 0);

  // 验证生成的数独结果文件是否存在
  std::ifstream file("./shudu_result.txt");
  EXPECT_TRUE(file.good());
}
// 运行所有的测试用例
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}