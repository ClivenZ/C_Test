#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ǵݹ�
int DigitSum_Nd(int num) {
	int Sum = 0;
	Sum = (num % 10) + (num / 10) % 10 + (num / 100) % 10 + (num / 1000);
	return Sum;
}

//�ݹ�
int Sum = 0;
int DigitSum(int num) {
		if (num > 9) {
			DigitSum(num / 10);
		}
		return Sum = Sum + (num % 10);
}
int main()
{
	int Num = 0;
	printf("�����룺");
	scanf("%d",&Num);
	//�ǵݹ�
	printf("%d��ÿһλ�ĺ�Ϊ��%d\n", Num, DigitSum_Nd(Num));
	//�ݹ�
	printf("%d��ÿһλ�ĺ�Ϊ��%d\n", Num, DigitSum(Num));
    system("pause");
    return 0;   
}