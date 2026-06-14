//#include<iostream>
//#include<vector>
//using namespace std;
//void findDuplicates(vector<int>nums, int n)
//{
//	int max = nums[0];
//	for (int i = 1; i < n; i++)
//	{
//		if (nums[i] > max)
//		{
//			max = nums[i];
//		}
//	}
//	int size = max + 1;
//	vector <int> fr(size);
//	for (int i = 0; i < size; i++)
//	{
//		fr[i] = 0;
//	}
//	for (int i = 0; i < n; i++)
//	{
//		fr[nums[i]]++;
//	}
//	bool found = false;
//	for (int i = 0; i < size; i++)
//	{
//		if (fr[i] != 0 && fr[i] != 1)
//		{
//			cout << i << " ";
//			found = true;
//		}
//	}
//	if (!found)
//	{
//		cout << "No Duplicate Found";
//	}
//	cout << endl;
//}
//
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
//	findDuplicates(nums, n);
//}