#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//�ݹ�
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
	printf("������N��ֵ");
	scanf("%d",&num);
	printf("������k��ֵ");
	scanf("%d", &k);
	//�ǵݹ�
	printf("%d^%d=%d\n",num,k,(int)pow(num,k));
	//�ݹ�
	printf("%d^%d=%d\n", num, k, Fun2(num, k));
    system("pause");
    return 0;   
}