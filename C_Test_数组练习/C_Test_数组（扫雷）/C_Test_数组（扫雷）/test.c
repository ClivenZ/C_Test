#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//1.使用二维数组来表示地图
//   a）地雷的布局图（char 类型的数组，用'0'表示不是地雷，'1'表示是地雷）
//   b）玩家看到的地图（哪些位置未翻开，哪些位置翻开），
//     （char 类型的数组表示，如果' '表示未翻开，如果是数组表示已经翻开，并且当前位置周围8个格子有几个雷）
//2.初始化
//   a）地雷的布局地图，先把这个二维数组全部都初始化成'0'，再随机设定若干个位置为地雷
//   b）玩家看到的地图，全部初始化成' '，表示为翻开
//3.先打印地图（玩家看到的地图），提示玩家出入坐标。
//4.如果玩家翻开的格子是地雷，则游戏结束（提示扫雷失败）
//5.如果玩家翻开的格子不是地雷，并且这个格子是地图上非地雷的最后一个位置，扫雷成功
//6.如果玩家翻开的不是地雷，且这个格子不是地图上最后一个非地雷位置，
//  就把地图上的位置设置为展开状态，并且更新该位置周围8个格子的地雷数


#define ROW 9
#define COL 9
#define MINE_COUNT 10

int Menu() {
	printf("==================\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("==================\n");
	printf("请输入您的选择：");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

void Init(char show_map[ROW + 2][COL + 2],
	      char mine_map[ROW + 2][COL + 2]) {
	//1.把show_map初始化全是' '
	for (int row = 0; row < ROW + 2;++row) {
		for (int col = 0; col < COL + 2;++col) {
			show_map[row][col] = ' ';
		}
	}
	//2.把mine_map初始化为全是'0'
	for (int row = 0; row < ROW + 2; ++row) {
		for (int col = 0; col < COL + 2; ++col) {
			mine_map[row][col] = '0';
		}
	}
	//3.把mmine_map哪些位置是地雷，排布好
	int mine_count = MINE_COUNT;
	while (mine_count > 0) {
		//尝试随机设置地雷
		//随机数产生的位置[1,9]
		int row = rand() % ROW + 1;
		int col = rand() % COL + 1;
		if (mine_map[row][col] == '1') {
			//当前随机产生的坐标已经有地雷了
			continue;
		}
		mine_map[row][col] = '1';
		--mine_count;
	}
}

void DisplayMap(char map[ROW + 2][COL + 2]) {
	//打印地图
	//不光要打印出地图的详细内容，顺便打印出坐标
	
	//先打印出左上角的空格
	printf("    ");
	//打印列的坐标
	for (int i = 1; i <= ROW;++i) {
		printf("%d ",i);
	}
	printf("\n");
	//打印上边框
	for (int i = 1; i <= ROW; ++i) {
		printf("---");
	}
	printf("\n");
	//按行打印地图的内容
	for (int row = 1; row <= ROW; ++row) {
		//先打印行号
		printf(" %d| ",row);
		//再打印该行的每一列
		for (int col = 1; col <= COL;++col) {
			printf("%c ",map[row][col]);
		}
		printf("\n");
	}
}


void UpdateShowMap(char show_map[ROW + 2][COL + 2], char mine_map[ROW + 2][COL + 2],
	int row, int col) {
	//统计当前位置周围8个格子有几个地雷，把数组更新到 show_map上
	int count = 0;
	//如果没有边框，则需要进行判定:
	//if (row - 1 >= 0 && row - 1 < ROW + 1
	//	&& col - 1 >= 0 && col - 1 < COL + 1) {
	//	if (mine_map[row - 1][col - 1 == '1']) {
	//		++count;
	//	}
	//}
	//有了边框之后:
	/*if (mine_map[row - 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row - 1][col] == '1') {
		++count;
	}
	if (mine_map[row - 1][col + 1] == '1') {
		++count;
	}
	if (mine_map[row][col - 1] == '1') {
		++count;
	}
	if (mine_map[row][col + 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col] == '1') {
		++count;
	}
	if (mine_map[row + 1][col - 1] == '1') {
		++count;
	}
	if (mine_map[row + 1][col + 1] == '1') {
		++count;
	}*/
	//上面的代码可以简化为
	count = (mine_map[row - 1][col - 1] - '0')
		+ (mine_map[row - 1][col] - '0')
		+ (mine_map[row - 1][col + 1] - '0')
		+ (mine_map[row][col - 1] - '0')
		+ (mine_map[row][col + 1] - '0')
		+ (mine_map[row + 1][col - 1] - '0')
		+ (mine_map[row + 1][col] - '0')
		+ (mine_map[row + 1][col + 1] - '0');
	//
	show_map[row][col] = '0' + count;
}
//每次调用Game()就进行一次游戏
void Game() {
	//再地图的外层加上一圈边框
	char show_map[ROW + 2][COL + 2];
	char mine_map[ROW + 2][COL + 2];
	//数组作为参数会隐式转换为指针，拿着数组名传到函数立案已经成为指针
	//再函数内部对参数进行修改是会影响到外部的数组的
	Init(show_map, mine_map);
	int safe_blank_count = 0;
	while (1) {
		DisplayMap(show_map);
		int row = 0;
		int col = 0;
		printf("请输入坐标:");
		scanf("%d %d", &row, &col);
		if (row < 1 || row >ROW || col < 1 || col > COL) {
			//坐标输入非法，需要注意！地图是带边框的！所以判定规则要小心
			printf("您输入的坐标不合法，请重新输入！\n");
			continue;
		}
		//验证是否踩到地雷
		if (mine_map[row][col] == '1') {
			printf("游戏结束！扫雷失败！\n");
			break;
		}
		//验证是否扫雷成功
		++safe_blank_count;
		if (safe_blank_count == ROW * COL - MINE_COUNT) {
			printf("游戏结束！扫雷成功！\n");
			break;
		}
		//更新地图的状态
		UpdateShowMap(show_map,mine_map,row,col);
		system("cls");
	}
	DisplayMap(mine_map);
}

int main()
{
	srand((unsigned)time(0));
	while (1) {
		int choice = Menu();
		if (choice == 0) {
			printf("GoodBye!\n");
			break;
		}
		if (choice == 1) {
			Game();
		}
	}
    system("pause");
    return 0;   
}