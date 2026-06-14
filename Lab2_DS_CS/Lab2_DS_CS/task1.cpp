//#include<iostream>
//#include<vector>
//using namespace std;
//void productExceptSelf(vector<int>& nums, int n, vector<int>&answer)
//{
//	int prod = 1;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (j != i)
//			{
//				prod = prod * nums[j];
//			}
//		}
//		answer[i] = prod;
//		prod = 1;
//	}
//	
//}
//int main()
//{
//	int n;
//	cout << "Enter the size of the array: ";
//	cin >> n;
//	vector<int>nums(n);
//	cout << "Enter " << n << " elements: ";
//	for (int i = 0; i < n; i++)
//	{
//		cin >> nums[i];
//	}
//	vector<int> ans(n);
//
//	productExceptSelf(nums, n, ans);
//	cout << "{";
//	for (int i = 0; i < n; i++)
//	{
//		cout  << ans[i]  ;
//		if (i != n - 1)
//		{
//			cout << ",";
//		}
//	}
//	cout << "}";
//}