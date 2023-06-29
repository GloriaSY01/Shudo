#include "gtest/gtest.h"
#include <fstream>
#include "../include/shudu.h"
// 定义测试套件
class Shudutest : public ::testing::Test {
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
	//为了防止全局变量混乱，使用了名词空间

// 测试生成数独终局的函数
TEST_F(Shudutest, TestProduceOutputIntoTxt) {
  int produce_num = 10;
  int result = produceOutputIntoTxt(produce_num);
  
  // 验证函数的返回值是否符合预期
  EXPECT_EQ(result, 0);

  // 验证生成的数独终局文件是否存在
  std::ifstream file("./shudu_final.txt");
  EXPECT_TRUE(file.good());
}

// 测试处理数独问题的函数
TEST_F(Shudutest, TestDealQuestion) {
  char* path = "questions.txt";
  int result = dealQuestion(path);

  // 验证函数的返回值是否符合预期
  EXPECT_EQ(result, 0);

  // 验证生成的数独结果文件是否存在
  std::ifstream file("./shudu_result.txt");
  EXPECT_TRUE(file.good());
}
TEST_F(Shudutest,TestMethod1)
{
	//测试越界值
	int a = produceOutputIntoTxt(0);
	int b = produceOutputIntoTxt(1000001);
	int c = produceOutputIntoTxt(-1);
  EXPECT_EQ(a, -1);
	EXPECT_EQ(b, -1);
  EXPECT_EQ(c, -1);
}
TEST_F(Shudutest,TestMethod2)
{
	//正常值
	int a = produceOutputIntoTxt(1000);
	EXPECT_EQ(a, 0);
}
TEST_F(Shudutest,TestMethod3)
{
  //测试正确的九宫格位置
	int a = getBlockNum(3, 3);
	EXPECT_EQ(a, 4);
}	
TEST_F(Shudutest,TestMethod4)
{
  //测试错误的九宫格位置
  int a = getBlockNum(0, 9);
  EXPECT_EQ(a, -1);
}

TEST_F(Shudutest,TestMethod6)
{
  //测试错误路径
  int a = dealQuestion("asdfadsfadga");
  EXPECT_EQ(a, -1);
}
TEST_F(Shudutest,TestMethod7)
{
  //测试错误文件
  int a = dealQuestion("ppp.txt");
  EXPECT_EQ(a, -1);
}
TEST_F(Shudutest,TestMethod8)
{
  //测试正确文件
  int a = dealQuestion("questions.txt");
  EXPECT_EQ(a, 0);
}
TEST_F(Shudutest,TestMethod9)
{
  //测试dfs返回正确
  int a = dfs(1, 1);
  EXPECT_EQ(a, 1);
}
TEST_F(Shudutest,TestMethod10)
{
  int col_count[9][10] = { 0 }, row_count[9][10] = { 0 }, block_count[9][10] = { 0 };
	BLFS bs[100];
	int mapp[9][9];
  memset(col_count, 1, sizeof(col_count));
  int a = dfs(0, 100);
  EXPECT_EQ(a, 0);
}

TEST(Shudutest, FileContent)
{
    int a = dealQuestion("questions.txt");
    // 检查文件是否成功写入
    FILE* fp = fopen("./shudu_result.txt", "r");
    EXPECT_FALSE(fp==nullptr);
    fclose(fp);
}
// 测试isValid函数
TEST(Shudutest, ValidNumber)
{
    // 验证解出的数独是否正确
  int puzzle[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };

    // 假设mapp已经被正确初始化
    bool result = isValid2(puzzle,0, 0, 1);
    EXPECT_FALSE(result);
}

TEST(Shudutest, InvalidRow)
{
    // 假设mapp已经被正确初始化
    int puzzle[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };
    bool result = isValid2(puzzle,0, 0, 5);
    EXPECT_FALSE(result);
}
TEST(Shudutest, InvalidColumn)
{
    int puzzle[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };
    // 假设mapp已经被正确初始化
    bool result = isValid2(puzzle,0, 0, 9);
    EXPECT_TRUE(result==false);
}

TEST(Shudutest, InvalidBlock)
{
  int puzzle[9][9] = {
    {5, 3, 4, 6, 7, 8, 9, 1, 2},
    {6, 7, 2, 1, 9, 5, 3, 4, 8},
    {1, 9, 8, 3, 4, 2, 5, 6, 7},
    {8, 5, 9, 7, 6, 1, 4, 2, 3},
    {4, 2, 6, 8, 5, 3, 7, 9, 1},
    {7, 1, 3, 9, 2, 4, 8, 5, 6},
    {9, 6, 1, 5, 3, 7, 2, 8, 4},
    {2, 8, 7, 4, 1, 9, 6, 3, 5},
    {3, 4, 5, 2, 8, 6, 1, 7, 9}
  };
    // 假设mapp已经被正确初始化
    bool result = isValid2(puzzle,0, 0, 2);
    EXPECT_FALSE(result);
}
// 测试solveshudu函数
TEST(Shudutest, SolvableShudu)
{
    // 假设mapp已经被正确初始化，包含一个有解的数独
    bool result = solveshudu();
    EXPECT_TRUE(result);
}

TEST(Shudutest, UnsolvableShudu)
{
    // 假设mapp已经被正确初始化，包含一个无解的数独
    bool result = solveshudu();
    EXPECT_FALSE(result);
}
TEST(Shudutest, InvalidPuzzle)
{
    int puzzle[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 0} // 该行最后一个格子缺失数字
    };

    int count = countshudusolu(puzzle);
    EXPECT_EQ(count, 0);
}
// 测试countshudusolu函数
TEST(Shudutest, ValidPuzzle)
{
    int puzzle[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    int count = countshudusolu(puzzle);
    EXPECT_EQ(count, 1);
}
// 测试generateshudu函数
TEST(Shudutest, ValidParameters)
{
    int gamesCount = 10;
    int difficulty = 2;

    generateshudu(gamesCount, difficulty);

    // 读取生成的数独游戏文件
    std::ifstream inputFile("shudu_games.txt");
    std::string line;
    std::vector<std::string> gameLines;

    while (std::getline(inputFile, line))
    {
        gameLines.push_back(line);
    }

    inputFile.close();

    // 检查生成的游戏数量
    EXPECT_EQ(gameLines.size(), gamesCount * 10);  // 每个游戏有9行数独数据 + 空行分隔

    // 检查游戏数据格式和难度
    for (int i = 0; i < gamesCount; i++)
    {
        int gameStartIndex = i * 11;  // 每个游戏开始的索引位置

        // 检查数独数据行格式
        for (int j = 0; j < 9; j++)
        {
            std::string gameLine = gameLines[gameStartIndex + j];
            std::vector<std::string> cells;

            // 按空格拆分单元格数据
            std::istringstream iss(gameLine);
            std::string cell;
            while (iss >> cell)
            {
                cells.push_back(cell);
            }

            // 检查单元格数量
            EXPECT_EQ(cells.size(), 9);

            // 检查单元格数据
            for (const std::string& cell : cells)
            {
                EXPECT_TRUE(cell == "$" || (cell.size() == 1 && cell[0] >= '0' && cell[0] <= '9'));
            }
        }

        // 检查空行分隔
        EXPECT_EQ(gameLines[gameStartIndex + 9], "");

        // 检查难度
        std::string gameDifficultyLine = gameLines[gameStartIndex + 10];
        EXPECT_EQ(gameDifficultyLine.size(), 1);
        EXPECT_TRUE(gameDifficultyLine[0] >= '1' && gameDifficultyLine[0] <= '3');
        EXPECT_EQ(gameDifficultyLine[0] - '0', difficulty);
    }
}
// 测试generateshudu2函数
TEST(Shudutest, ValidParameters2)
{
    int gamesCount = 10;
    int min = 2;
    int max = 17;

    generateshudu2(gamesCount, min, max);

    // 读取生成的数独游戏文件
    std::ifstream inputFile("shudu_games2.txt");
    std::string line;
    std::vector<std::string> gameLines;

    while (std::getline(inputFile, line))
    {
        gameLines.push_back(line);
    }

    inputFile.close();

    // 检查生成的游戏数量
    EXPECT_EQ(gameLines.size(), gamesCount * 10);  // 每个游戏有9行数独数据 + 空行分隔

    // 检查游戏数据格式和挖空数目
    for (int i = 0; i < gamesCount; i++)
    {
        int gameStartIndex = i * 11;  // 每个游戏开始的索引位置

        // 检查数独数据行格式
        for (int j = 0; j < 9; j++)
        {
            std::string gameLine = gameLines[gameStartIndex + j];
            std::vector<std::string> cells;

            // 按空格拆分单元格数据
            std::istringstream iss(gameLine);
            std::string cell;
            while (iss >> cell)
            {
                cells.push_back(cell);
            }

            // 检查单元格数量
            EXPECT_EQ(cells.size(), 9);

            // 检查单元格数据
            for (const std::string& cell : cells)
            {
                EXPECT_TRUE(cell == "$" || (cell.size() == 1 && cell[0] >= '0' && cell[0] <= '9'));
            }
        }

        // 检查空行分隔
        EXPECT_EQ(gameLines[gameStartIndex + 9], "");

        // 检查挖空数目
        std::string holesLine = gameLines[gameStartIndex + 10];
        std::istringstream iss(holesLine);
        int holes;
        iss >> holes;
        EXPECT_TRUE(holes >= min && holes <= max);
    }
}
// 测试generateshudu3函数
TEST(Shudutest, ValidParameters3)
{
    int gamesCount = 10;
    int difficulty = 2;

    generateshudu3(gamesCount, difficulty);

    // 读取生成的数独游戏文件
    std::ifstream inputFile("shudu_games3.txt");
    std::string line;
    std::vector<std::string> gameLines;

    while (std::getline(inputFile, line))
    {
        gameLines.push_back(line);
    }

    inputFile.close();

    // 检查生成的游戏数量
    EXPECT_EQ(gameLines.size(), gamesCount * 11);  // 每个游戏有9行数独数据 + 1行空行 + 1行挖空数目

    // 检查游戏数据格式和挖空数目
    for (int i = 0; i < gamesCount; i++)
    {
        int gameStartIndex = i * 11;  // 每个游戏开始的索引位置

        // 检查数独数据行格式
        for (int j = 0; j < 9; j++)
        {
            std::string gameLine = gameLines[gameStartIndex + j];
            std::vector<std::string> cells;

            // 按空格拆分单元格数据
            std::istringstream iss(gameLine);
            std::string cell;
            while (iss >> cell)
            {
                cells.push_back(cell);
            }

            // 检查单元格数量
            EXPECT_EQ(cells.size(), 9);

            // 检查单元格数据
            for (const std::string& cell : cells)
            {
                EXPECT_TRUE(cell == "$" || (cell.size() == 1 && cell[0] >= '0' && cell[0] <= '9'));
            }
        }

        // 检查空行分隔
        EXPECT_EQ(gameLines[gameStartIndex + 9], "");

        // 检查挖空数目行
        std::string holesLine = gameLines[gameStartIndex + 10];
        std::istringstream iss(holesLine);
        int holes;
        iss >> holes;

        // 由于使用的是唯一解判定，所以挖空数目应等于设定的难度级别
        if (difficulty == 1)
        {
            EXPECT_EQ(holes, 40);
        }
        else if (difficulty == 2)
        {
            EXPECT_EQ(holes, 50);
        }
        else if (difficulty == 3)
        {
            EXPECT_EQ(holes, 60);
        }
    }
}
// 测试splitString函数
TEST(Shudutest, ValidInput)
{
    std::string str = "Hello,World,How,Are,You";
    std::string delimiter = ",";

    std::vector<std::string> tokens = splitString(str, delimiter);

    // 检查分割后的结果
    EXPECT_EQ(tokens.size(), 5);
    EXPECT_EQ(tokens[0], "Hello");
    EXPECT_EQ(tokens[1], "World");
    EXPECT_EQ(tokens[2], "How");
    EXPECT_EQ(tokens[3], "Are");
    EXPECT_EQ(tokens[4], "You");
}

TEST(Shudutest, EmptyInput)
{
    std::string str = "";
    std::string delimiter = ",";

    std::vector<std::string> tokens = splitString(str, delimiter);

    // 检查分割后的结果
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0], "");
}

TEST(Shudutest, NoDelimiterFound)
{
    std::string str = "Hello World";
    std::string delimiter = ",";

    std::vector<std::string> tokens = splitString(str, delimiter);

    // 检查分割后的结果
    EXPECT_EQ(tokens.size(), 1);
    EXPECT_EQ(tokens[0], "Hello World");
}
// 运行所有的测试用例
int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}















