#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include <time.h>

//1.使用字符类型二维数组来表示棋盘（3 * 3）
//使用‘x’表示玩家的子，‘0’表示电脑的子
//2.玩家落子，给玩家一个友好的提示，提示让玩家落子，输入一组坐标
//== > 判定游戏结束
//a、玩家获胜
//b、电脑获胜
//c、和棋
//d、游戏没结束
//3.电脑落子，随机数的方式
//== > 判定游戏结束
//a、玩家获胜
//b、电脑获胜
//c、和棋
//d、游戏没结束

#define ROW 3
#define COL 3

//g_前缀表示全局变量
char g_broad[ROW][COL];

//初始化
void Init() {
	//把数组中的每个元素都初始化成空格
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			g_broad[row][col] = ' ';
		}
	}
}
//打印棋盘
void Print() {
	for (int row = 0; row < ROW; ++row) {
		printf("| %c | %c | %c |\n",
			g_broad[row][0], g_broad[row][1], g_broad[row][2]);
		if (row != ROW - 1) {
			printf("|---|---|---|\n");
		}
	}
}
//玩家落子
void PlayerMove() {
	printf("玩家落子！\n");
	while (1) {
		printf("请输入一组坐标(row col):");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= ROW || col < 0 || col >= COL) {
			printf("坐标输入非法！请重新输入！\n");
			continue;
		}
		if (g_broad[row][col] != ' ') {
			printf("当前位置已经有子了，请重新输入！\n");
			continue;
		}
		g_broad[row][col] = 'x';
		break;
	}
}
//如果满了返回1，如果没满返回0
int IsFull() {
	//遍历棋盘
	for (int row = 0; row < ROW; ++row) {
		for (int col = 0; col < COL; ++col) {
			if (g_broad[row][col] == ' ');
			return 0;
		}
	}
	return 1;
}
//返回当前的游戏胜负情况
//返回‘x’表示玩家获胜，返回‘0’表示电脑获胜
//返回'q'表示和棋，返回' '表示游戏没有结束
char CheckWinner() {
	//先检查所有的行
	for (int row = 0; row < ROW; ++row) {
		if (g_broad[row][0] == g_broad[row][1]
			&& g_broad[row][0] == g_broad[row][2]
			&& g_broad[row][0] != ' '){
			return g_broad[row][0];
			}
	}
	//再检查所有的列
	for (int col = 0; col < COL; ++col) {
		if (g_broad[0][col] == g_broad[1][col]
			&& g_broad[0][col] == g_broad[2][col]
			&& g_broad[0][col] != ' ') {
			return g_broad[0][col];
		}
	}
	//再检查所有的对角
	if (g_broad[0][0] == g_broad[1][1]
		&& g_broad[0][0] == g_broad[2][2]
		&& g_broad[0][0] != ' ') {
		return g_broad[0][0];
	}
	if (g_broad[2][0] == g_broad[1][1]
		&&g_broad[2][0] == g_broad[0][2]
		&&g_broad[2][0] != ' ') {
		return g_broad[2][0];
	}
	if (IsFull()) {
		return 'q';
	}
	return' ';
}

void ComputerMove() {
	printf("电脑落子！\n");
	while (1) {
		int row = rand() % ROW;
		int col = rand() % COL;
		if (g_broad[row][col] != ' ') {
			continue;
		}
		g_broad[row][col] = 'o';
		break;
	}
}
int main()
{
	srand((unsigned)time(0));
	Init();
	char winner = '\0';
	while (1) {
		Print();
		PlayerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		ComputerMove();
		winner = CheckWinner();
		if (winner != ' ') {
			break;
		}
		system("cls");
	}
	Print();
	if (winner == 'x') {
		printf("你赢了\n");
	}
	else if (winner == '0') {
		printf("你输了!\n");
	}
	else{
		printf("和棋!\n");
	}
    system("pause");
    return 0;   
}