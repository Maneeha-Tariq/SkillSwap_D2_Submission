#include<iostream>
#include<queue>
using namespace std;
int strictlyIncreasingQueue(queue<int> q)
{
	if (q.empty()) return 0;
	int count = 1;
	queue<int>temp;
	int s = q.size();
	for (int i = 0; i < s-1; i++)
	{
		int fr = q.front();
		q.pop();
		if (!q.empty() && q.front() > fr)
		{
			count += 1;
		}
		else
		{
			temp.push(count);
			count = 1;
		}
	}
	if (temp.empty())
	{
		return count;
	}
	else
	{
		temp.push(count);
		int size = temp.size();
		int max = temp.front();
		temp.pop();
		for (int i = 0; i < size-1 ; i++)
		{
			if (temp.front() > max)
			{
				max = temp.front();
			}
			temp.pop();
		}
		return max;
	}
 }
int main()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(2);
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	cout << strictlyIncreasingQueue(q);
	return 0;
}