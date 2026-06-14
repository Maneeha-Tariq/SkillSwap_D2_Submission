//#include<iostream>
//#include<queue>
//#include<string>
//using namespace std;
//struct Box
//{
//	string id;
//	int weight;
//	Box(string bId,int w)
//	{
//		id = bId;
//		weight = w;
//	}
//};
//int main()
//{
//	int weight;
//	cin >> weight;
//	int n; int w;
//	cin >> n;
//	queue<Box>q; queue<Box> load;
//	string bId;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> bId;
//		cin >> w;
//		Box b(bId, w);
//		q.push(b);
//	}
//	int totalWeigh = 0;
//	while (!q.empty())
//	{
//		if (totalWeigh + q.front().weight > weight)
//		{
//			break;
//		}
//		totalWeigh += q.front().weight;
//		load.push(q.front());
//		q.pop();
//	}
//	cout << "Loaded: ";
//	if (!load.empty())
//	{
//		while (!load.empty())
//		{
//			cout << load.front().id;
//			cout << "(";
//			cout << load.front().weight;
//			cout << ")  ";
//			load.pop();
//		}
//		cout << endl;
//	}
//	else
//	{
//		cout << "none"<< endl;
//	}
//	string notLoad = " ";
//	if (!q.empty())
//	{
//		notLoad = q.front().id;
//	}
//	cout << "Remaining in Queue : ";
//	if (!q.empty())
//	{
//		while (!q.empty())
//		{
//			cout << q.front().id;
//			cout << "(";
//			cout << q.front().weight;
//			cout << ")  ";
//			q.pop();
//		}
//		cout << endl;
//	}
//	else
//	{
//		cout << "none"<< endl;
//	}
//
//	if (notLoad != " ")
//	{
//		cout << "Note: " << notLoad << " was not loaded -- would exceed capacity\n ";
//	}
//	
//	return 0;
//}
