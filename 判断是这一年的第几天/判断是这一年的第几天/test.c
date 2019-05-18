#include<stdio.h>
#include<stdlib.h>

int main()
{
	int y, m, d; int i, sum=0;
	int a[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 }; 
	printf("请输入时间(以空格间隔)：");
	scanf_s("%d %d %d",&y,&m,&d);
	for(i=1;i<m;i++)
	{
		sum += a[i];
	}
	sum += d;
	if ((y % 100 == 0 && y % 4 == 0) || y % 400 == 0 && m > 3)
		sum += 1;
	printf("这是%d年的第%d天\n",y,sum);
	system("pause");
	return 0;
}