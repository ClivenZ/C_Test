#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//쳲���������
// 1�� 1�� 2 ��3�� 5�� 8��13��21��34��������n

//�ǵݹ�
int Factorial_Nd(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int cur = 0;    //��N��
	int Last1 = 1;  //��N-1��
	int Last2 = 1;  //��N-2��
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
	printf("������N��");
	scanf("%d",&num);
	//�ǵݹ�
	printf("��%d��쳲�������Ϊ%d\n", num,Factorial_Nd(num));
	//�ݹ�
	printf("��%d��쳲�������Ϊ%d\n", num, Factorial(num));
	system("pause");
    return 0;   
}