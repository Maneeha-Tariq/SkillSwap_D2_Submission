#include<iostream>
#include<vector>
using namespace std;
void insertionSort(int * arr,int size)
{
	int s = size;
	for (int i = 1; i < s; i++)
	{
		int j = i;
		while (j > 0 && arr[j] < arr[j - 1])
		{
			int temp = arr[j];
			arr[j] = arr[j - 1];
			arr[j - 1] = temp;
			j--;
		}
	}
}
void selectionSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		int min = i;
		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i)
		{
			int temp = arr[min];
			arr[min] = arr[i];
			arr[i] = temp;
		}
	}
}
void bubbleSort(int* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j + 1] < arr[j])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[7];
	arr[0] = 10;
	arr[1] = 4;
	arr[2] = 11;
	arr[3] = 2;
	arr[4] = 5;
	arr[5] = 1;
	arr[6] = 3;
	/*int a[7];
	a[0] = 10;
	a[1] = 4;
	a[2] = 11;
	a[3] = 2;
	a[4] = 5;
	a[5] = 1;
	a[6] = 3;*/ 
	bubbleSort(arr, 7);
	for (int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
}