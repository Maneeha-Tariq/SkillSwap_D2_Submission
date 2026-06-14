//#include<iostream>
//using namespace std;
//void fun(int arr[], int n)
//{
//	int* output = new int[n];
//	int max = arr[0];
//	
//    for(int i=0;i<n;i++)
//	{ 
//		if (arr[i] > max)
//		{
//			max = arr[i];
//		}
//		output[i] = max;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		arr[i] = output[i];
//	}
//	delete[] output;
//}
//
//int main()
//{
//	int arr[5] = { 0,6,1,3,9 };
//	int size = sizeof(arr) / sizeof(arr[0]);
//	fun(arr, size);
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << " ";
//	}
//	
//	return 0;
//}