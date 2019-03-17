#include<stdio.h>
#include<stdlib.h>
int main()
{
	int arr[] = {0,6,12,22,24,29,41,60,69,72};
	int to_find = 60;
	int left = 0, mid = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < to_find)
		{
			left = mid + 1;
		}
		else if (arr[mid] > to_find)
			right = mid - 1;
		else
			break;
	}
	if (left <= right)
		printf("找到了，下标为：%d!\n", mid);
	else
		printf("查找不到!\n");
    
	system("pause");
    return 0;   
}