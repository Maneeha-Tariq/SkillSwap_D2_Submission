#include<iostream>
#include<vector>
using namespace std;
void rotateVectorKTimes(vector<int>&nums, int n, int k)
{
	int last;
	for (int i = 0; i < k; i++)
	{
		last = nums[n - 1];
		for (int j = n - 1; j > 0; j--)
		{
			nums[j] = nums[j - 1];
		}
		nums[0] = last;
	}
}
int main()
{
	int n;
	cout << "Enter the size of the array: ";
	cin >> n;
	vector<int> nums(n);
	int k;
	cout << "Enter the number of rotations k: ";
	cin >> k;
	cout << "Enter " << n << " elements: ";
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	rotateVectorKTimes(nums, n, k);
	cout << "{";
	for (int i = 0; i < n; i++)
	{
		cout << nums[i];
		if (i != n - 1)
		{
			cout << ",";
		}
	}
	cout << "}";
	return 0;
}