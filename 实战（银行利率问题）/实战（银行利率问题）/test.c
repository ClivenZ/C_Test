#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
/******************************************************/
//��֪����������ȡ��ͬ���޵���Ϣ���ʷֱ�Ϊ��
//0.315% ����һ��
//0.330% ���޶���
//0.345% ��������
//0.375% ��������
//0.420% ���ް���
//Ҫ�������Ǯ�ı�������ޣ�����ʱ�ܴ����еõ�����Ϣ�뱾��ĺϼơ�
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