#include<iostream>
#include<cstring>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

#include <sstream>
using namespace std;

typedef struct BlockForSort {
	int x, y;	//数独空白点的位置
	int count;			//计数器，用来排序
	int size;		//一个数独中空白点的个数
}BLFS;	//用来找最小的块


bool judge(int x, int y, int i);
int getBlockNum(int x, int y);
bool cmp(BLFS& a, BLFS& b);
int produceOutputIntoTxt(int produce_num);
int dealQuestion(char* path);
int dfs(int num, int size);
void setFlag(int x, int y, int i, int flag);
bool judge(int x, int y, int i);
bool isValid(int row, int col, int num);
bool solveshudu();
bool isValid2(int puzzle[9][9], int row, int col, int num);
int countshudusolu(int puzzle[9][9]);
void generateshudu(int gamesCount, int difficulty);
void generateshudu2(int gamesCount, int min,int max);
void generateshudu3(int gamesCount, int difficulty);
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) ;
