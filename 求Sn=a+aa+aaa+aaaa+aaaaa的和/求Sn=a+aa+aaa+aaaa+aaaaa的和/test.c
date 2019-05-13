#include<stdio.h>
#include<stdlib.h>
int main()
{
	int a,i,Sn=0;
	printf("«Î ‰»Îaµƒ÷µ£∫");
	scanf_s("%d",&a);
	a = a * 10000 + a * 1000 + a * 100 + a * 10 + a; //a=aaaaa
	for (i=1;i<=5;i++)
	{
		Sn = Sn + a;
		a = a / 10;
	}
	printf("Sn=a+aa+aaa+aaaa+aaaaa=%d",Sn);
    system("pause");
    return 0;   
}