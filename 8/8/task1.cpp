//#include<iostream>
//#include<queue>
//#include<string>
//using namespace std;
//int main()
//{
//	int n;
//	cout << "Enter no of commands you want to enter: ";
//	cin >> n;
//	string s;
//	string name;
//	queue<string>q;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> s;
//		if (s == "ARRIVE")
//		{
//			cin >> name;
//			q.push(name);
//		}
//		else if (s == "SERVE")
//		{
//			if (q.empty())
//			{
//				cout << "Queue is empty\n";
//				continue;
//			}
//			cout << "Serving: " << q.front()<< endl;
//			q.pop();
//		}
//		else if (s == "SKIP")
//		{
//			if (q.size() < 2)  continue;
//			
//			q.push(q.front());
//			q.pop();
//		}
//		else if (s == "COUNT")
//		{
//			cout << "Count: " << q.size()<< endl;
//		}
//		else if (s == "DISPLAY")
//		{
//			if (q.empty())
//			{
//				cout << "Queue is empty\n";
//				continue;
//			}
//			cout << "Queue: ";
//			int count = q.size();
//			while (!q.empty()&& count!=0)
//			{
//				cout << q.front();
//				if (count > 1)
//				{
//					cout << " -> ";
//				}
//				q.push(q.front());
//				q.pop();
//				count--;
//				cout << endl;
//			}
//		}
//
//
//	}
//
//	return 0;
//}