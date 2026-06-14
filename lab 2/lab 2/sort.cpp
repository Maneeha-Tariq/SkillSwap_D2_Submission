#include <iostream>
#include<stdlib.h>
#include<chrono>
using namespace std;
using namespace chrono;

void selectionSort(int arr[], int N)
{
	int minIndex = 0;
	int i = 0;
	for (; i < N - 1; i++)
	{
		minIndex = i;
		for (int j = i + 1; j < N; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
		
		
	}
}
void bubbleSort(int arr[], int N)
{
	for (int i = 0; i < N - 1; i++)
	{
		for (int j =0 ; j < N - i - 1; j++)
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
void insertionSort(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		int val = arr[i];
		int j = i - 1;
		while (j >= 0 && val < arr[j])
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = val;
	}
}
//int main()
//{
	/*srand(time(0));*/
	/*int N = 100;
	int arr[100];*/
	/*int N = 10;
	int arr[10];*/
	//randomly populated selectionSort
	/*for (int i = N - 1, j = 0; i >= 0; j++, i--)
	{
		arr[j] = rand() % N;
	}*/

	/*descending order*/
	/*for (int i = N - 1; i >= 0; i--)
	{
		arr[i] = i;
	}*/
	
	/*for (int i = N -3;i >= 0; i--)
	{
		
		arr[i] = i+1;
	}
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}*/



	
	
	/*randomly populated in milliseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<milliseconds>(end - start).count();
		sum=sum+ duration_cast<milliseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	/*randomly populated in microseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<microseconds>(end - start).count();
		sum=sum+ duration_cast<microseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	/*randomly populated in nanoseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
		sum=sum+ duration_cast<nanoseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/


	//randomly populated bubble in milliseconds
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<milliseconds>(end - start).count();
		sum=sum+ duration_cast<milliseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	//randomly populated bubble in microseconds
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<microseconds>(end - start).count();
		sum=sum+ duration_cast<microseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	/*randomly populated bubble in nanoseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
		sum=sum+ duration_cast<nanoseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/


//}



//randomly populated in milliseconds
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<milliseconds>(end - start).count();
		sum=sum+ duration_cast<milliseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	/*randomly populated in microseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<microseconds>(end - start).count();
		sum=sum+ duration_cast<microseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	/*randomly populated in microseconds*/
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		selectionSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
		sum=sum+ duration_cast<nanoseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/


	/*//randomly populated bubble in milliseconds
	long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<milliseconds>(end - start).count();
		sum=sum+ duration_cast<milliseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	//randomly populated bubble in microseconds
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<microseconds>(end - start).count();
		sum=sum+ duration_cast<microseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/

	//randomly populated bubble in nanoseconds
	/*long double sum = 0;
	for (int i = 0; i < 10; i++)
	{
		time_point<steady_clock>start, end;
		start = steady_clock::now();
		bubbleSort(arr, N);
		end = steady_clock::now();
		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
		sum=sum+ duration_cast<nanoseconds>(end - start).count();
	}
	cout << endl<<"Average_time: " << sum / 10 << endl;*/














//void bubbleSort(int arr[], int n)
//{
//	for (int i = 0; i < n - 1; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//			}
//		}
//	}
//}
//int main()
//{
//	int n = 1000;
//	int arr[100];
//
//	for (int i = n - 1, j = 0; i < n; j++, i--)
//	{
//		arr[j] = 1 + rand() % 1000;
//	}
//	double sum = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		time_point<steady_clock>start, end;
//		start = steady_clock::now();
//		selectionSort(arr, n);
//		end = steady_clock::now();
//		cout << endl << fixed << duration_cast<nanoseconds>(end - start).count();
//		sum = sum + duration_cast<nanoseconds>(end - start).count();
//	}
//	cout << "Average time: " << sum / 10 << endl;
//}