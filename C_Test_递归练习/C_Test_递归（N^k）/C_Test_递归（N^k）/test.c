#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//递归
int Fun2(int num, int k) {
	if (k == 0) {
		return 1;
	}
	return num * Fun2(num, k - 1);

}
int main()
{
	int num = 0;
	int k = 0;
	printf("请输入N的值");
	scanf("%d",&num);
	printf("请输入k的值");
	scanf("%d", &k);
	//非递归
	printf("%d^%d=%d\n",num,k,(int)pow(num,k));
	//递归
	printf("%d^%d=%d\n", num, k, Fun2(num, k));
    system("pause");
    return 0;   
}