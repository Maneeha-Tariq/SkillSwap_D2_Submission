//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//int minAddToMakeValid(string s)
//{
//	stack<char>stk; int balance = 0;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == '(')
//		{
//			stk.push(s[i]);
//			balance++;
//		}
//		else if (s[i] == ')')
//		{
//			if (!stk.empty() && stk.top()=='(')
//			{
//				stk.pop();
//				balance--;
//			}
//			else if (stk.empty())
//			{
//				balance++;
//			}
//		}
//	}
//	return balance;
//	
//}
//void insertAtBottom(stack<int>& stk, int x)
//{
//	if (stk.empty())
//	{
//		stk.push(x);
//		return;
//	}
//	else
//	{
//		int temp = stk.top();
//		stk.pop();
//		insertAtBottom(stk, x);
//		stk.push(temp);
//	}
//}
//void reverseStack(stack<int>& stk)
//{
//	if (stk.empty())
//	{
//		return;
//	}
//	else
//	{
//		int temp = stk.top();
//		stk.pop();
//		reverseStack(stk);
//		insertAtBottom(stk, temp);
//
//	}
//}
//int main()
//{
//	stack<int> s;
//	s.push(1);
//	s.push(2);
//	s.push(3);
//	s.push(4);
//
//	reverseStack(s);
//	cout << "After reverse: ";
//	while (!s.empty())
//	{
//		cout << s.top()<< " ";
//		s.pop();
//	}
//	
//
//	return 0;
//}