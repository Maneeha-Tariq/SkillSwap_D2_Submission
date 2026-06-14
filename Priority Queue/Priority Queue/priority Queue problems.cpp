#include<iostream>
#include<queue>
#include<deque>
#include<vector>
#include<string>
using namespace std;
int minCost(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < v.size(); i++)
	{
		pq.push(v[i]);
	}
	int totalCost = 0;
	while (pq.size() > 1)
	{
		int first = pq.top();
		pq.pop();
		int second = pq.top();
		pq.pop();
		int cost = first + second;
		totalCost += cost;
		pq.push(cost);
	}

	return totalCost;
}
int solve(vector<int>&A,int B) 
{
	priority_queue<int>pq;
	for (int i = 0; i < A.size(); i++)
	{
		pq.push(A[i]);
	}
	int cost = 0;
	for (int i = B; i > 0; i--)
	{
		int first = pq.top();
		pq.pop();
		cost += first;
		pq.push(--first);
	}
	return cost;
}
void sortColors(vector<int>& nums)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < nums.size(); i++)
	{
		pq.push(nums[i]);
	}
	int size = pq.size();
	for (int i = 0; i < size; i++)
	{
		nums[i] = pq.top();
		pq.pop();
	}
}
long long maxKelements(vector<int>& nums, int k) 
{
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < nums.size(); i++)
	{
		pq.push({ nums[i],i });
	}
	long long int score = 0;
	for (int i = 0; i < k; i++)
	{
		int first = pq.top().first;
		score += first;
		int second = pq.top().second;
		nums[second] = ceil(first/3.0);
		pq.pop();
		pq.push({ nums[second],second });
	}
	return score;
}
int findKthLargest(vector<int>& nums, int k) 
{
	priority_queue<int>pq;
	for (int i = 0; i < nums.size(); i++)
	{
		pq.push(nums[i]);
	}
	for (int i = 0; i < k-1; i++)
	{
		pq.pop();
	}
	return pq.top();
}
int lastStoneWeight(vector<int>& stones)
{
	priority_queue<pair<int, int>>pq;
	for (int i = 0; i < stones.size(); i++)
	{
		pq.push({ stones[i], i });
	}

	while (pq.size() >= 2)
	{
		int x = pq.top().first;
		int xInd = pq.top().second;
		pq.pop();
		int y = pq.top().first;
		int yInd = pq.top().second;
		if (x == y)
		{
			pq.pop();
		}
		else
		{
			pq.pop();
			int newY = y - x;
			pq.push({ (newY < 0 ? (-1) * newY : newY),yInd });
		}
	}
	return !pq.empty() ? pq.top().first : 0;
}
queue<string> generate1_to_Nbinary(int n)
{
	queue<string>q; queue<string>inp;
	q.push("1");
	for (int i = 1; i <=n; i++)
	{
		string s = q.front();
		q.pop();
		inp.push(s);
		string n = s;
		q.push(n+'0');
		string t = s;
		q.push(t+'1');
	}
	return inp;
}
int sumOfKthLargestElement(vector<int>& v,int k)
{
	priority_queue<int>pq;
	for (int i = 0; i < v.size(); i++)
	{
		pq.push(v[i]);
	}
	int sum = 0;
	for (int i = k; i > 0; i--)
	{
		sum += pq.top();
		pq.pop();
	}
	return sum;
}
vector<int> mergeKSortedArray(vector<vector<int>>& v)
{
	priority_queue<int, vector<int>, greater<int>>pq;
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			pq.push(v[i][j]);
		}
	}
	vector<int>res;
	int size = pq.size();
	for (int i = 0; i < size; i++)
	{
		res.push_back(pq.top());
		pq.pop();
	}
	return res;
}
int main()
{
	/*vector<int> v = { 2,7,4,1,8,1 };
	cout << lastStoneWeight(v);*/
	/*queue<string>s = generate1_to_Nbinary(6);
	while (!s.empty())
	{
		cout << s.front() << " ";
		s.pop();
	}*/
	/*vector<int>v = { 2,7,4,1,8,1 };
	cout<< sumOfKthLargestElement(v, 3);*/
	vector<vector<int>>v(3);
	// inserting values
	v[0].push_back(1);
	v[0].push_back(4);
	v[0].push_back(7);

	v[1].push_back(2);
	v[1].push_back(5);
	v[1].push_back(8);

	v[2].push_back(3);
	v[2].push_back(6);
	v[2].push_back(9);

	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
	vector<int> res = mergeKSortedArray(v);
	for (int i = 0; i < res.size(); i++)
	{
		cout << res[i] << " ";
	}
	return 0;
}