#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char  password[5] = {0};int i=0;
	printf("*****��ӭ��½��ϵͳ*****\n");
	while(i<3)
	{
		    printf("���������룺");
		    scanf("%s", &password);
			printf("\n");	
	        if (strcmp(password,"1234") == 0)      //strcmp()�ַ����ȽϺ���
			{
				printf("��ӭ��½!\n");
				break;
			}
			else
			{
				i++;
				printf("���������������������\n");
				printf("��ʣ%d�λ���!\n", 3 - i);
				printf("\n");
			}
	}
	if (i == 3)
	{
		printf("�����������ﵽ����,��������ϵͳ��\n");
	}
    system("pause");
    return 0;   
}
