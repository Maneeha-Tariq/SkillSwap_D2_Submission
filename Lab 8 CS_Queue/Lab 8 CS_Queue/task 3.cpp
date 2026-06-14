#include<iostream>
#include<queue>
#include<deque>
using namespace std;
int CircleGameWinner(int n, int k)
{
	deque<int>q;
	vector<int>v(k);
	for (int i = 1; i <= n; i++)
	{
		q.push_back(i);
	}
	while (q.size() > 1)
	{
		for (int i = 0; i < k; i++)
		{
			v[i] = q.front();
			q.pop_front();
			q.push_back(v[i]);
		}
		q.pop_back();
	}
	return q.front();
}
int main()
{
	cout << CircleGameWinner(5, 2);
	return 0;
}