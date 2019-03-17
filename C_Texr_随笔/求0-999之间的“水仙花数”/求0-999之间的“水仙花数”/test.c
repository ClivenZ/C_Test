#include<stdio.h>
#include<stdlib.h>
#include <math.h>
int main()
{
	int i, j, m, n	;
	for ( i = 100; i <= 999; i++)
	{
		j = i / 100;
		m = i / 10 - j * 10;
		n = i % 10;
		if (i == pow(j,3)+pow(m,3)+pow(n,3))
		{
			printf("Ë®ÏÉ»¨Êý£º%d\n",i);
		}
	}
    system("pause");
    return 0;   
}