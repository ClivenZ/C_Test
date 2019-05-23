#define  _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main()
{
	char  password[5] = {0};int i=0;
	printf("*****欢迎登陆本系统*****\n");
	while(i<3)
	{
		    printf("请输入密码：");
		    scanf("%s", &password);
			printf("\n");	
	        if (strcmp(password,"1234") == 0)      //strcmp()字符串比较函数
			{
				printf("欢迎登陆!\n");
				break;
			}
			else
			{
				i++;
				printf("密码错误，请重新输入密码\n");
				printf("还剩%d次机会!\n", 3 - i);
				printf("\n");
			}
	}
	if (i == 3)
	{
		printf("密码错误次数达到上限,请重启本系统。\n");
	}
    system("pause");
    return 0;   
}
