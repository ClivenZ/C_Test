#include<stdio.h>
#include<stdlib.h>
int main()
{
	char a = 0;
	printf("请输入字符（仅限字母）：");
	//ASCII表中'A'与'a'中相差32
		do
		{
			a = getchar();
			if (a <= 'z'&&a >= 'a')
				printf("%c", a - 32);
			else if (a <= 'Z'&&a >= 'A')
				printf("%c", a + 32);
			else
				break;
		} 
		while (a);
	system("pause");
	return 0;
}