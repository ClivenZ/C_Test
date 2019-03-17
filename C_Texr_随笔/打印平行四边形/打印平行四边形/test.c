#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n, i, j;
	printf("Please putin the number:");
	scanf("%d",&m);
	for (n = 0;n < m;n++)
	{
		for (i = 1;i < m-n;i++)
		{
			printf(" ");
		}
		for (j = 0;j < m;j++)
		{
			printf("* ");
		}
		printf("\n");
	}
	system("pause");
    return 0;   
}