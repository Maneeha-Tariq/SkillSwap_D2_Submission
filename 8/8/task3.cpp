#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct Task
{
	string name;
	int burstTime;
	Task(string n, int t)
	{
		name = n;
		burstTime = t;
	}
};
int main()
{
	int n; 
	cin >> n;
	int bTime; string iden; queue<Task>q; queue<string>order;
	for (int i = 0; i < n; i++)
	{
		cin >> iden >> bTime;
		Task t(iden, bTime);
		q.push(t);
	}
	int i = 1;
	while (!q.empty())
	{
		q.front().burstTime--;
		if (q.front().burstTime > 0)
		{
			cout << "Turn " << i << ":  " << q.front().name << " ran  | Remaining: " << q.front().burstTime << endl;
			q.push(q.front());
			q.pop();
		}
		else if (q.front().burstTime == 0)
		{
			order.push(q.front().name);
			cout << "Turn " << i << ":  " << q.front().name << " ran  | Remaining: " 
		    << q.front().burstTime<< " -> "<< q.front().name<< " Completed\n";
			q.pop();
		}
		i++;
	}
	if (q.empty())
	{
		cout << "Completion Order: ";
		int count = order.size();
		while (!order.empty())
		{
			cout<< order.front();
			if (count > 1)
			{
				cout << " , ";
			}
			order.pop();
			count--;
		}
	}
	return 0;
}