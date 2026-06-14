#include <iostream>
#include<chrono>
using namespace std;
using namespace chrono;
void selectionSort(int arr[], int n)
{
	int minIndex;
	
	for (int i=0 ; i < n - 1; i++)
	{
		 minIndex = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		/*int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
		cout << "\nbb";*/
		swap(arr[i], i);
	}
}
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int linearSearch(int arr[], int n, int key)
{
	for (int i = 0; i < n ; i++)
	{
		if (arr[i] == key)
		{
			return i;
		}
	}
	return -1;
}
int binarySearch(int arr[], int n, int key)
{
	int low = 0;
	int high = n - 1;
	int mid = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if(arr[mid]>key)
		{
			high = mid + 1;
		}
		else
		{
			low = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int n = 1000;
	int arr[100];

	for (int i = n-1,j=0;i < n;j++,i--)
	{
		arr[j] = 1 + rand() % 1000;
	}
	double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, n);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
		sum=sum+ duration_cast<nanoseconds>(end - start).count();
	}
	cout << "Average time: " << sum / 10 << endl;
}
