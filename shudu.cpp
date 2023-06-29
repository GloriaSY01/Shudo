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
namespace DEAL {
	int col_count[9][10] = { 0 }, row_count[9][10] = { 0 }, block_count[9][10] = { 0 };
	BLFS bs[100];
	int map[9][9];
	//为了防止全局变量混乱，使用了名词空间
}

namespace STORE {
	char store[300000000] = { 0 };
	long count = 0;
}
char out[9][9];

int getBlockNum(int x, int y) {
	//获得空格是哪一块九宫格的的，从零开始计数
	if (x < 0 || y < 0 || x >= 9 || y>8) return -1;
	return ((x / 3) * 3 + (y / 3));
}


bool cmp(BLFS& a, BLFS& b) {
	return a.count > b.count;
}
int produceOutputIntoTxt(int produce_num) {		//本函数用于生成数独终局
	int count = produce_num;
	int	trans_arr[9] = { 1,2,3,4,5,6,7,8,9 };	//用来交换的数字
	int cols[9] = { 0,1,2,3,4,5,6,7,8 };	//用来交换的行
	int sub;		//一个中间值，后面会用到
	string table[9] = {	//数独模板
	"123456789",
	"456789123",
	"789123456",
	"234567891",
	"567891234",
	"891234567",
	"345678912",
	"678912345",
	"912345678"
};
	if (count <= 0||count>1000000) {
		cout << "please input N which>0 and <=1000000" << endl;
		return -1;
	}
	remove("./shudu_final.txt");
	FILE* fp = fopen("./shudu_final.txt", "wt");
	if (fp == NULL) {
		cout << "err" << endl;
		return -1;
	}
	STORE::count = 0;
	memset(STORE::store, 0, sizeof(STORE::store));
	do {//前两列的交换
		do {//三到五列交换
			do {//六到八列的交换
				do {//前八个数字的交换
					for (int i = 0; i < 9; i++) {
						for (int j = 0; j < 9; j++) {
							sub = (int)(table[cols[i]][j] - '0') - 1;
							//将生成的数独终局保存在大数组中，空间换时间
							STORE::store[STORE::count++] = trans_arr[sub] + '0';
							if (j == 8)STORE::store[STORE::count++] = '\n';
							else STORE::store[STORE::count++] = ' ';
						}
					}
					STORE::store[STORE::count++] = '\n';
					count--;
					if (count <= 0) {
						//生成结束，开始将大数组一次写入文件
						fwrite(STORE::store, sizeof(char), STORE::count, fp);
						cout << "over create shudu_final" << endl;
						fclose(fp);
						return 0;
					}
				} while (next_permutation(trans_arr, trans_arr + 8));
			} while (next_permutation(cols + 6, cols + 9));
		} while (next_permutation(cols + 3, cols + 6));
	} while (next_permutation(cols + 1, cols + 3));

	cout << "over or err" << endl;
	return 0;
}
int dealQuestion(char* path) {
    char shudu[1024];
    int x, y;
    int _col[9] = { 0 }, _row[9] = { 0 }, _block[9] = { 0 };
    //分别代表行列以及九宫格里可以填的数字。比如block_count[1][7]=1代表第块已经存在7了。
    using namespace DEAL;
    FILE* fp = fopen(path, "r");
    if (fp == NULL) {
        cout << "error open file, please check the question file path" << endl;
        return -1;
    }
    int soku_num = 0;
    do {
        memset(shudu, 0, sizeof(shudu));
        if (fread(shudu, sizeof(char), 163 * sizeof(char), fp) < 162) {        //读到少于一个数独问题的字符
            if (feof(fp)) break; //判断是否到文件尾
            else {        //出错，终止
                cout << "error read file" << endl;
                return -1;
            }
        };
        x = 0; y = 0;

        {            //用来初始化一些值
            memset(bs, 0, sizeof(bs));
            memset(_col, 0, sizeof(_col));
            memset(_block, 0, sizeof(_block));
            memset(_row, 0, sizeof(_row));
            memset(row_count, 0, sizeof(row_count));
            memset(col_count, 0, sizeof(col_count));
            memset(block_count, 0, sizeof(block_count));
        }

        for (int i = 0; i < 162; i++) {
            if (shudu[i] == ' ' || shudu[i] == '\n') continue;
            else {
                if (shudu[i] == '$') map[x][y] = 0;
                else map[x][y] = int(shudu[i] - '0');
                if (y >= 8) {
                    y = 0;
                    x++;
                }
                else y++;
            }
        }
        //将数独文件转化为int型存储
        int count_bs = 0;
        int sub_map;

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (map[i][j] == 0) {
                    bs[count_bs].x = i;
                    bs[count_bs].y = j;
                    count_bs++;
                }
                else {
                    sub_map = map[i][j];
                    setFlag(i, j, sub_map, 1);
                    _row[i]++;
                    _col[j]++;
                    _block[getBlockNum(i, j)]++;
                }
            }
        }

        x = 0; y = 0;
        for (int i = 0; i < count_bs; i++) {
            x = bs[i].x; y = bs[i].y;
            bs[i].count = _row[x] + _col[y] + _block[getBlockNum(x, y)];
        }//记录空白格周围已经占用的点，占用的越多这个点的搜索优先级越高，越先搜索

        sort(bs, bs + count_bs, cmp);    //排序，把count高的值排到前面

        if (dfs(0, count_bs) == false) {
            printf("error dfs\n");
            cout << "shudu error" << soku_num << endl;
            if (soku_num >= 100) {
                printf("too much error, please check the question file\n");
                return -1;
            }//出错一百个以上直接结束
            soku_num++;
            continue;
        }

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (map[i][j] == 0) STORE::store[STORE::count++] = '$';
                else STORE::store[STORE::count++] = char(map[i][j] + '0');
                if (j == 8) STORE::store[STORE::count++] = '\n';
                else STORE::store[STORE::count++] = ' ';
            }
        }
        STORE::store[STORE::count++] = '\n';
        //将数独结果存储到大数组里，空间换时间
    } while (!feof(fp));
    FILE* wrfp = fopen("./shudu_result.txt", "wt");
    fwrite(STORE::store, sizeof(char), STORE::count, wrfp);    //将大数组写入文件
    fclose(wrfp);
    fclose(fp);
    cout << "over deal question" << endl;
    return 0;
}


void setFlag(int x, int y, int i, int flag) {
	DEAL::col_count[y][i] = flag;
	DEAL::row_count[x][i] = flag;
	DEAL::block_count[getBlockNum(x, y)][i] = flag;
}

int dfs(int num, int size) {
	if (num == size) {
		return true;
	}
	else {
		int x = DEAL::bs[num].x, y = DEAL::bs[num].y;
		for (int i = 1; i <= 9; i++) {
			if (judge(x, y, i)) {
				DEAL::map[x][y] = i;
				setFlag(x, y, i, 1);
				if (dfs(num + 1, size)) return true;
				setFlag(x, y, i, 0);
				DEAL::map[x][y] = 0;
			}
		}
		return false;
	}
}

bool judge(int x, int y, int i) {
	return !DEAL::col_count[y][i] && !DEAL::row_count[x][i] && !DEAL::block_count[getBlockNum(x, y)][i];
}

bool isValid(int row, int col, int num) {
	using namespace DEAL;
    // 检查行是否合法
    for (int i = 0; i < 9; i++) {
        if (map[row][i] == num) {
            return false;
        }
    }

    // 检查列是否合法
    for (int i = 0; i < 9; i++) {
        if (map[i][col] == num) {
            return false;
        }
    }

    // 检查小九宫格是否合法
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}
// 使用回溯算法填充数独格子
bool solveshudu() {
	using namespace DEAL;
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (map[row][col] == 0) {
                // 尝试填充数字 1-9
                for (int num = 1; num <= 9; num++) {
                    if (isValid(row, col, num)) {
                        // 填充数字并递归求解
                        map[row][col] = num;
                        if (solveshudu()) {
                            return true;
                        }
                        // 回溯
                        map[row][col] = 0;
                    }
                }
                return false;  // 无法填充任何数字
            }
        }
    }
    return true;  // 数独已填充完成
}
// 生成数独游戏(不同难度或数量)
void generateshudu(int gamesCount, int difficulty) {
	using namespace DEAL;
    random_device rd;
    mt19937 gen(rd());

    ofstream outputFile("shudu_games.txt");  // 打开输出文件

    for (int i = 0; i < gamesCount; i++) {
        // 初始化数独格子为0
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                map[row][col] = 0;
            }
        }

        solveshudu();  // 填充数独格子
		// 随机挖洞以创建不同的难度
        int holesToRemove = 0;
        if (difficulty == 1) {
            holesToRemove = 40;  // 简单难度
        } else if (difficulty == 2) {
            holesToRemove = 50;  // 中等难度
        } else if (difficulty == 3) {
            holesToRemove = 60;  // 困难难度
        }

        vector<pair<int, int>> positions;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                positions.push_back(make_pair(row, col));
            }
        }

        shuffle(positions.begin(), positions.end(), gen);

        for (int j = 0; j < holesToRemove; j++) {
            int row = positions[j].first;
            int col = positions[j].second;
            map[row][col] = -1;  // 使用 -1 表示空白处
        }
		// 输出数独游戏到文件中
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (map[row][col] == -1) {
                    outputFile << "$";
                } else {
                    outputFile << map[row][col];
                }

                if (col != 8) {
                    outputFile << " ";
                }
            }
            outputFile << endl;
        }

        outputFile << endl;  // 添加空行分隔不同的数独游戏
    }

    outputFile.close();  // 关闭输出文件
}
// 生成数独游戏(制定挖空数目)
void generateshudu2(int gamesCount, int min,int max) {
	using namespace DEAL;
    random_device rd;
    mt19937 gen(rd());

    ofstream outputFile("shudu_games2.txt");  // 打开输出文件

    for (int i = 0; i < gamesCount; i++) {
        // 初始化数独格子为0
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                map[row][col] = 0;
            }
        }

        solveshudu();  // 填充数独格子
		// 随机挖洞以创建不同的难度
        int holesToRemove = 0;
        int min=2;
    	int max=17;
    	holesToRemove=(rand()%(max-min+1))+ min;
        vector<pair<int, int>> positions;
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                positions.push_back(make_pair(row, col));
            }
        }

        shuffle(positions.begin(), positions.end(), gen);

        for (int j = 0; j < holesToRemove; j++) {
            int row = positions[j].first;
            int col = positions[j].second;
            map[row][col] = -1;  // 使用 -1 表示空白处
        }
		// 输出数独游戏到文件中
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (map[row][col] == -1) {
                    outputFile << "$";
                } else {
                    outputFile << map[row][col];
                }

                if (col != 8) {
                    outputFile << " ";
                }
            }
            outputFile << endl;
        }

        outputFile << endl;  // 添加空行分隔不同的数独游戏
    }

    outputFile.close();  // 关闭输出文件
}


// 函数：字符串分割
std::vector<std::string> splitString(const std::string& str, const std::string& delimiter) {
    std::vector<std::string> tokens;
    size_t pos = 0;
    size_t lastPos = 0;
    while ((pos = str.find(delimiter, lastPos)) != std::string::npos) {
        tokens.push_back(str.substr(lastPos, pos - lastPos));
        lastPos = pos + delimiter.length();
    }
    tokens.push_back(str.substr(lastPos));
    return tokens;
}

int main(int argc,char **argv) {
	if (argc == 1) {	//未输入命令行参数，报错并返回
		cout << "please input command in cmd line" << endl;
		return 0;
	}
	else {
		if (!strcmp(argv[1], "-c")) {
			int produce_num = atoi(argv[2]);
			//若无法转换则代表存在非法输入
			if (produce_num!=0) {
				int produce_num = atoi(argv[2]);
				if (produceOutputIntoTxt(produce_num) == -1) {
					cout << "终局生成失败" << endl;
					return -1;
				}
			}
			else {
				cout << "please input number after -c" << endl;
				return 0;
			}
		}
		else if (!strcmp(argv[1], "-s")) {
			if (dealQuestion(argv[2]) == -1) {
				cout << "error deal shudu question" << endl;
					return -1;
			}
		}
		else if (!strcmp(argv[1], "-n")) {
            if (argc == 3) {
                int numPuzzles = atoi(argv[2]);
                if (numPuzzles > 0) {
                    generateshudu(numPuzzles, 1);  // 生成初级难度的数独游戏
                    cout << "Successfully generated " << numPuzzles << " shudu games of easy difficulty in shudu_games.txt" << endl;
                } 
			}
			else if (string(argv[3]) == "-r") {
				int numPuzzles = atoi(argv[2]);
            	string range = argv[4];
				std::vector<std::string> rangeParams = splitString(range, "~");
        		if (rangeParams.size() != 2) {
            		std::cout << "Invalid range parameter." << std::endl;
            		return 0;
        		}
        		int minHoles = std::stoi(rangeParams[0]);
        		int maxHoles = std::stoi(rangeParams[1]);
            	generateshudu2(numPuzzles, minHoles, maxHoles);
            	cout << "Successfully generated " << numPuzzles << " shudu games with holes count ranging from "
                     	<< minHoles << " to " << maxHoles << "." << endl;
            } 
			else if(string(argv[3]) == "-m"){
				int numPuzzles = atoi(argv[2]);
                int difficulty = atoi(argv[4]);
                if (numPuzzles > 0 && (difficulty >= 1 && difficulty <= 3)) {
                    generateshudu(numPuzzles, difficulty);
                    cout << "Successfully generated " << numPuzzles << " shudu games of difficulty " << difficulty << " in shudu_games.txt" << endl;
                } else {
                    cout << "Please input a valid number of games and difficulty level." << endl;
                }
			}
			else {
                cout << "Invalid range format. Please use the format 'min~max', where min and max are positive integers." << endl;
            }
    }
	else {	//错误输入，报错
			cout << "input cmd error!" << endl;
			return 0;
		}
    }
        } 
		