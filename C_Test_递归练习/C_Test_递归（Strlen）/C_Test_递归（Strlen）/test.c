#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

//�ǵݹ�
//��������Ϊ�����Ĳ���
//��C�����У������������Ϊ�����Ĳ������ͻᱻ��ʽת����ָ��,ָ��������λԪ��
int Strlen_Nd(char* str) {
	int i = 0;
	while (str[i] != '\0') {
		++i;
	}
	return i;
}
//�ݹ�
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
	printf("�������ַ�����");
	scanf("%c",&str);
	//�ǵݹ�
	printf("�ַ����ĳ���Ϊ��%d\n",Strlen_Nd(str));
	//�ݹ�
	printf("�ַ����ĳ���Ϊ��%d\n", Strlen(str));
    system("pause");
    return 0;   
}