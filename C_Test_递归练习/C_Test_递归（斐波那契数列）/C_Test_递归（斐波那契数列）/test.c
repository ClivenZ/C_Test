#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//斐波那契数列
// 1， 1， 2 ，3， 5， 8，13，21，34。。。，n

//非递归
int Factorial_Nd(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int cur = 0;    //第N项
	int Last1 = 1;  //第N-1项
	int Last2 = 1;  //第N-2项
	for (int i = 3; i <= n; ++i) {
		cur = Last1 + Last2;
		Last2 = Last1;
		Last1 = cur;
	}
	return cur;
}
int Factorial(int n) {
	if (n == 1 || n ==2) {
		return 1;
	}
	return Factorial(n - 1) + Factorial(n - 2);
}

int main()
{
	int num = 0;
	printf("请输入N：");
	scanf("%d",&num);
	//非递归
	printf("第%d项斐波那契数为%d\n", num,Factorial_Nd(num));
	//递归
	printf("第%d项斐波那契数为%d\n", num, Factorial(num));
	system("pause");
    return 0;   
}