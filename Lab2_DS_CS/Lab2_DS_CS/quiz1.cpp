//#include<iostream>
//#include<vector>
//using namespace std;
//void removeOccurances(vector<int>&nums)
//{
//	vector<int> result;
//	
//	for (int i = 0; i < nums.size(); i++)
//	{
//		bool isDuplicate = false;
//		for (int j = 0; j < result.size(); j++)
//		{
//			if (nums[i] == result[j])
//			{
//				isDuplicate = true;
//				break;
//			}
//		}
//		if (!isDuplicate)
//		{
//			result.push_back(nums[i]);
//		}
//	}
//	nums = result;
//
//
//}
//int main()
//{
//	vector<int> nums = { 1, 2, 4,4, 3, 1, 4 };
//
//	removeOccurances(nums);
//
//	cout << "After removing duplicates: ";
//	for (int x : nums)
//		cout << x << " ";
//}