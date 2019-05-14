#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a[10] = {52,31,4,12,28,7,69,81,62,65};
	int i=2, max=a[1];
	for (; i <= 10; i++)
	{
		if (a[i]>max)
			max = a[i];
	}
	printf("这十个数中的最大值为%d\n",max);
	system("pause");
	return 0;
}