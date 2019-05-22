#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i;
	for (i = 1000; i <= 2000; i++)
	{
		if (i == 1000 || i == 2000)
			if (i % 400 == 0)
				printf("%d是闰年  ",i);
		if (i % 4 == 0)
			if (i % 100 != 0)
				printf("%d是闰年  ",i);
	}
	system("pause");
	return 0;
}