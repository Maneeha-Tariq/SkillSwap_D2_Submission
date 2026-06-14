#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
vector<int> nextGreaterElement( vector<int>&nums1,vector<int>& nums2)
{
	stack<int>stk; vector<int>ans(nums2.size(),-1);
	for (int i = 0; i < nums2.size(); i++)
	{
		if (stk.empty())
		{
			stk.push(i);
		}
		else
		{
			while (!stk.empty() && nums2[stk.top()] < nums2[i])
			{
				ans[stk.top()] = nums2[i];
				stk.pop();
			}
			stk.push(i);
		}
	}
	for (int i = 0; i < nums1.size(); i++)
	{
		for (int j = 0; j < nums2.size(); j++)
		{
			if (nums1[i] == nums2[j])
			{
				nums1[i] = ans[j];
				break;
			}
		}
	}
	return nums1;
}
int main()
{
	vector<int>v = { 2,4};
	vector<int>v2 = { 1,2,3,4};
	vector<int>t = nextGreaterElement(v,v2);
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << " ";
	}
	return 0;
}