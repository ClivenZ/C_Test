#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void game(int m)
{
	int n;
	printf("Please putin:");
	while (1)
	{
		scanf("%d", &n);
		printf("\n");
		if (n > m)
		{
			printf("*******   * Guess big!    ********\n");
			printf("Please putin:"); 
		}
		if (n < m)
		{
			printf("*******   * Guess small!  ********\n");
			printf("Please putin:"); 
		}
		if (n == m)
		{
			printf("*******   * You're right! ********\n");
			break;
		}
	}
}
void meun()
{
	printf("*******************************\n");
	printf("*******    * 1. play   ********\n");
	printf("*******    * 0. exit   ********\n");
	printf("*******************************\n");
}
int main()
{
	srand((unsigned)time(NULL));    //初始化 => 随机数产生器
	int m = rand() % 101;           //生成一个随机数m（100以内的整数)
	int i;
	do
	{
		meun();
		scanf("%d", &i);            //进入菜单，1进行游戏，0退出游戏
		if (i == 1)
		{
			game(m);
		}
	} while (i == 0);
	system("pause");
    return 0;   
}