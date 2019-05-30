#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<Windows.h>
int main()
{
	char str1[] = {"Welcome to my world!"};
	char str2[] = {"####################"};
	int left = 0;
	//int right = sizeof(str1) - 1 - 1;  //存在\0空字符
	int right = strlen(str1) - 1;      //strlen获取的长度不包括\0
	while (left <= right)
	{
		str2[left] = str1[left];
		str2[right] = str1[right];
		++left; --right;
		printf("%s\n",str2);
		Sleep(500);             //Windows函数，延时
		system("cls");          //每执行一次，清屏一次
	}
    system("pause");
    return 0;   
}