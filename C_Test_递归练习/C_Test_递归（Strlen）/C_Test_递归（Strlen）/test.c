#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//非递归
//把数组作为函数的参数
//在C语言中，如果把数组作为函数的参数，就会被隐式转换成指针,指向数组首位元素
int Strlen_Nd(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		++i;
	}
	return i;
}
//递归
//"abcd" => 1 + "bcd"
//"bcd"  => 1 + "cd"
//"cd"   => 1 + "d"
//"d"    => 1 + ""
int Strlen(char* str) {
	if (str[0] == '\0') {
		return 0;
	}
	return 1 + Strlen(str + 1);
}
int main()
{
	char str[] = {0};
	printf("请输入字符串：");
	scanf("%c",&str);
	//非递归
	printf("字符串的长度为：%d\n",Strlen_Nd(str));
	//递归
	printf("字符串的长度为：%d\n", Strlen(str));
    system("pause");
    return 0;   
}