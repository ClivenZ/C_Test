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
	srand((unsigned)time(NULL));    //��ʼ�� => �����������
	int m = rand() % 101;           //����һ�������m��100���ڵ�����)
	int i;
	do
	{
		meun();
		scanf("%d", &i);            //����˵���1������Ϸ��0�˳���Ϸ
		if (i == 1)
		{
			game(m);
		}
	} while (i == 0);
	system("pause");
    return 0;   
}