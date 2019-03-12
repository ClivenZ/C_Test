#include<stdio.h>
#include<stdlib.h>

void Swap(int* a,int* b ) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int BubbleSort(int* array, int size,int Is_Desc) {
	int bound = 0;
	for (; bound < size; ++bound) {
		for (int cur = size - 1; cur > bound;--cur) {
			if (Is_Desc == 0) {
				if (array[cur] < array[cur - 1]) {
					Swap(&array[cur],&array[cur - 1]);
				}
			}
			else if (Is_Desc == 1) {
				if (array[cur - 1] < array[cur]) {
					Swap(&array[cur], &array[cur - 1]);
				}
			}
		}
	}
	return;
}
int BinarySearch(int* array, int size, int value) {
	int left = 0;
	int right = size - 1;
	int mid = 0;
	while (left <= right) {
		mid = (right + left) / 2;
		if (array[mid] < value) {
			left = mid + 1;
		}
		else if (array[mid] > value) {
			right = mid - 1;
		}
		else {
			break;
		}
	}
	if (left <= right) {
		printf("Find it!The Num is %d!\n", mid);
	}
	else {
		printf("Can't find it!\n");
	}
	return 1;
}
int main()
{
	int arr[] = {98,65,12,33,54,13,38,1,100,20};
	int size = sizeof(arr) / sizeof(arr[0]);
	int value = 13;
	BubbleSort(arr, size, 0);
	BinarySearch(arr,size,value);
    system("pause");
    return 0;   
}