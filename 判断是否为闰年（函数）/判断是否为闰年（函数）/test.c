#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int Isleapyear(int year)
{
	if (year % 100 == 0)
	{
		if (year % 400 == 0)
		{
			printf("%d is a leap year.\n", year);
		}
		else
		{
			printf("%d isn't a leap year.\n", year);
		}	 
	}
	else
	{
		if (year % 4 == 0)
		{
			printf("%d is a leap year\n",year);
		}
		else
		{
			printf("%d isn't a leap year\n",year);
		}
	}
	return year;
}
int main()
{
	int year;
	printf("Please putin the year:");
	scanf("%d", &year);
	Isleapyear(year);
    system("pause");
    return 0;   
}