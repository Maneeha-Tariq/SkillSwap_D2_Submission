#include<iostream>
#include<string>
#include<vector>
#include<math.h>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
	TreeNode(int x,TreeNode*left,TreeNode*right):val(x),left(left),right(right){}
};
bool helper(int x,int temp,long long &t)
{
	if (x < 0) return false;
	if (x == 0)
	{
		if (t == temp)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int c1 = x % 10;
	t = t * 10 + c1;
	x = x / 10;
	return helper(x, temp,t);
}
bool isPalindrome(int x)
{
	long long t = 0;
	int temp = x;
	return helper(x, temp,t);
}

bool isPowerOfTwo(int n)
{
	if (n <= 0) return false;
	if (n == 1) return true;
	if (n % 2 != 0) return false;
	return isPowerOfTwo(n/2);
}
vector<int>v;
void helper(TreeNode* r)
{
	if (!r) return;
	helper(r->left);
	v.push_back(r->val);
	helper(r->right);
}
int minAbsDiff(TreeNode* root)
{
	helper(root);
	int mini = 0; int size = v.size();
	for (int i = 0; i < size-1; i++)
	{
		if (i < size && i + 1 < size)
		{
			int m = v[i] - v[i + 1];
			if (m < 0) m = m * (-1);
			if (m < mini) mini = m;
		}
	}
	return mini;
}
int removeDuplicates(vector<int>& nums)
{
	int track = 1;
	for (int i = 0; i < nums.size(); i++)
	{
		if (nums[i] != nums[i-1])
		{
			nums[track] = nums[i];
			track++;
		}
	}
	return track;
}
int searchIndex(vector<int>& nums, int target)
{
	int low = 0;
	int high = nums.size() - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		if (target < nums[mid])
		{
			high = mid - 1;
		}
		else if (target > nums[mid])
		{
			low = mid + 1;
		}
		else if (target == nums[mid])
		{
			return mid;
		}
	}
	return low;
}
int main()
{
	int n = 10;
	cout << isPowerOfTwo(n);

	return 0;
}