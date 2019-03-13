#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//∑«µ›πÈ
int Factor_Nd(int num) {
	int Sum = 1;
	for (int i = 1; i <= num; ++i) {
		Sum = Sum * i;
	}
	return Sum;
}

//µ›πÈ
//n! => 1*2*3...*n
//=> n * (n-1)!
//(n-1) => (n-1) * (n-2)!
int Factor(int num) {
	if (num == 1) {
		return 1;
	}
	return num * Factor(num - 1);
}
int main()
{
	int Num = 0;
	printf("«Î ‰»ÎNµƒ÷µ£∫");
	scanf("%d",&Num);
	//∑«µ›πÈ
	printf("%d ! = %d\n",Num,Factor_Nd(Num));
	//µ›πÈ
	printf("%d ! = %d\n", Num, Factor(Num));
    system("pause");
    return 0;   
}