//#include<iostream>
//#include<stack>
//#include<queue>
//using namespace std;
////without disturbing the order of queue preserve the elements as it at last
//void printAllQueue(queue<int>&q)
//{
//	int n = q.size();
//	while (n--)
//	{
//		cout << q.front();
//		q.push(q.front());
//		q.pop();
//	}
//}
//void reverse(queue<int>& q)
//{
//	stack<int>stk;
//	int n = q.size();
//	for (int i = 0; i < n ;i++)
//	{
//		stk.push(q.front());
//		q.pop();
//	}
//	while (!stk.empty())
//	{
//		q.push(stk.top());
//		stk.pop();
//	}
//}
//// o(n) time
//int timeToBuyTickets(vector<int>& tickets, int k)
//{
//	int n = tickets.size();
//	int time = 0;
//	for (int i = 0; i <= k; i++)
//	{
//		time += min(tickets[k], tickets[i]);
//	}
//	for (int i = k + 1; i < n; i++)
//	{
//		time += min(tickets[k]-1, tickets[i]);
//	}
//	return time;
//}
////n^2 approach
//int timeToBuyTicketn2time(vector<int>& tickets, int k)
//{
//	queue<int>q;
//	for (int i = 0; i < tickets.size(); i++)
//	{
//		q.push(i);
//	}
//	int time = 0;
//	while (tickets[k] != 0)
//	{
//		tickets[q.front()]--;
//		if (tickets[q.front()])
//		{
//			q.push(q.front());
//			q.pop();
//		}
//		else
//		{
//			q.pop();
//		}
//		time++;
//	}
//	return time;
//}
//int main()
//{
//	//queue<int>q;
//	//q.push(1);
//	//q.push(2);
//	//q.push(3);
//	//q.push(4);
//	////printAllQueue(q);
//	////cout << "\n";
//	////cout<< q.size();
//	//reverse(q);
//	//printAllQueue(q);
//	vector<int> t = { 2,3,2 };
//	cout << timeToBuyTicketn2time(t, 2);
//	return 0;
//}