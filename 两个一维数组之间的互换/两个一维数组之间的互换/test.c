#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a1[5] = {1,3,5,7,9};
	int a2[5] = {2,4,6,8,0};
	int i, j;
	//���ԭ�����飻
	printf("����a1��ֵΪ��");
	for (i = 0;i < 5;i++)
	{
		printf("%d,", a1[i]);
	}
	printf("\n");
	printf("����a2��ֵΪ��");
	for(j = 0;j < 5;j++)
	{
	printf("%d,",a2[j]);
    }
	printf("\n");
    //��������Ļ���
	for (i = 0;i < 4;i++)
	{
		j = 0;
		j = a1[i]; a1[i] = a2[i]; a2[i] = j;
	}
	//����µ�����
	printf("����n_a1��ֵΪ��");
	for (i = 0; i < 5; i++)
	{
		printf("%d,", a1[i]);
	}
	printf("\n");
	printf("����n_a2��ֵΪ��");
	for (j = 0; j < 5; j++)
	{
		printf("%d,", a2[j]);
	}
	printf("\n");
	system("pause");
    return 0;   
}