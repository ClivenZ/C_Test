#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/******************************************************/
//已知银行整存整取存款不同期限的月息利率分别为：
//0.315% 期限一年
//0.330% 期限二年
//0.345% 期限三年
//0.375% 期限五年
//0.420% 期限八年
//要求输入存钱的本金和期限，求到期时能从银行得到的利息与本金的合计。
/******************************************************/
int InterestRate(int putin, int date)
{
	double sum = 0;
	if (date == 1)
	{
		sum = (putin * (0.315 / 100)) * 12 + putin;
	}
	else if (date == 2)
	{
		sum = (putin * (0.350 / 100)) * 12 + putin;
	}
	else if (date == 3)
	{
		sum = (putin * (0.350 / 100)) * 12 + putin;
	}
	else if (date == 5)
	{
		sum = (putin * (0.345 / 100)) * 12 + putin;
	}
	else if (date == 8)
	{
		sum = (putin * (0.420 / 100)) * 12 + putin;
	}
	else
	{
		printf("An incalid putin!\n");
	}
	return sum;
}
int main()
{
	int meony, date;
	while (1)
	{
		printf("Plese putin the number of meony:");
		scanf("%d", &meony);
		printf("Please putin the number of date:");
		scanf("%d", &date);
		if (InterestRate(meony, date) != 0)
		{
			printf("You'll get %d after %d year.\n", InterestRate(meony, date), date);
		}
	}

    system("pause");
    return 0;   
}