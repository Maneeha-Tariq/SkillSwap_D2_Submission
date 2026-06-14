//#include<iostream>
//#include<stack>
//#include<string>
//#include<vector>
//using namespace std;
//int score(vector<string>& operations)
//{
//	stack<int>s;
//	for (int i = 0; i < operations.size(); i++)
//	{
//	    if (operations[i] != "C" && operations[i] != "D" && operations[i] != "+")
//		{
//			s.push(stoi(operations[i]));
//		}
//		else if (operations[i] == "C")
//		{
//			s.pop();
//		}
//		else if (operations[i] == "D")
//		{
//			s.push(s.top()*2);
//		}
//		else if (operations[i] == "+")
//		{
//			if (!s.empty() && s.size() >= 2)
//			{
//				int a = s.top();
//				s.pop();
//				int b = s.top();
//				int plus = a + b;
//				s.push(a);
//				s.push(plus);
//			}
//			else
//			{
//				cout << "Insufficient values to compute the result of + operation\n";
//				return -1;
//			}
//		}
//	}
//	int sum = 0;
//	while (!s.empty())
//	{
//		sum += s.top();
//		s.pop();
//	}
//	return sum;
//}
//int main()
//{
//	int nCase;
//	cout << "Enter number of test cases: ";
//	cin >> nCase;
//	for (int i = 0; i < nCase; i++)
//	{
//		int op;
//		cout << "\nEnter number of operations to perform: ";
//		cin >> op;
//		vector<string> v;
//		for (int j = 0; j < op; j++)
//		{
//			string inp;
//			cin >> inp;
//			v.push_back(inp);
//		}
//		cout << "\nResult: " << score(v)<< endl;
//
//	}
//	return 0;
//}