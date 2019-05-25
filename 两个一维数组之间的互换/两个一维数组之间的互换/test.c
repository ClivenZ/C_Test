#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a1[5] = {1,3,5,7,9};
	int a2[5] = {2,4,6,8,0};
	int i, j;
	//输出原有数组；
	printf("数组a1的值为：");
	for (i = 0;i < 5;i++)
	{
		printf("%d,", a1[i]);
	}
	printf("\n");
	printf("数组a2的值为：");
	for(j = 0;j < 5;j++)
	{
	printf("%d,",a2[j]);
    }
	printf("\n");
    //进行数组的互换
	for (i = 0;i < 4;i++)
	{
		j = 0;
		j = a1[i]; a1[i] = a2[i]; a2[i] = j;
	}
	//输出新的数组
	printf("数组n_a1的值为：");
	for (i = 0; i < 5; i++)
	{
		printf("%d,", a1[i]);
	}
	printf("\n");
	printf("数组n_a2的值为：");
	for (j = 0; j < 5; j++)
	{
		printf("%d,", a2[j]);
	}
	printf("\n");
	system("pause");
    return 0;   
}