//#include<iostream>
//#include<vector>
//using namespace std;
//int printSubarraysSumK(vector<int>nums, int n, int k)
//{
//	int count = 0;
//	
//	for (int i = 0; i < n; i++)
//	{
//		int sum = 0;
//		for (int j = i; j < n; j++)
//		{
//			sum += nums[j];
//			if (sum == k)
//			{
//				cout << "SubArray Found: [";
//				for (int x = i; x <= j; x++)
//				{
//					cout << nums[x];
//					if (x != j)
//					{
//						cout << ",";
//					}
//				}
//				cout << "]\t-> sum = " << k << endl;
//				count++;
//			}
//		}
//	}
//	return count;
//}
//
//
//
//int main()
//{
//	int n;
//	cout << "Enter the size of the array: ";
//	cin >> n;
//	int sum;
//	cout << "Enter the target sum k: ";
//	cin >> sum;
//	vector<int>nums(n);
//	cout << "Enter "<< sum <<  " elements: ";
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//	
//	int c = printSubarraysSumK(nums, n, sum);
//	cout << "Number of SubArrays: " << c;
//}