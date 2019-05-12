#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a, b, c;
	printf("请输入两个数a,b：");
	scanf_s("%d,%d",&a,&b);
	if (a < b) 
	{
		c = a; a = b; b = c;
	}
	while (a % b != 0)
	{
		c = a % b;a = b;b = c;
	}
	printf("最大公约数为：%d",b);
	system("pause");
	return 0;
}