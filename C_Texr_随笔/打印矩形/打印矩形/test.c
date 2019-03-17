#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int main()
{
	int m, n,i;
	printf("Please putin the number:");
	scanf("%d", &m);
	for (i = 0; i < m; i++)
	{
		for (n = 0; n < m; n++)
		{
				printf("* ");
		}
		printf("\n");
	}

    system("pause");
    return 0;   
}