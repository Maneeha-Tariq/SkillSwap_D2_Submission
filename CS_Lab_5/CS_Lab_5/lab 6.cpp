//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//bool booleanExp(string str)
//{
//	stack<char>stk;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (str[i] == ',')
//		{
//			continue;
//		}
//		else if (str[i] != ')')
//		{
//			stk.push(str[i]);
//		}
//		else if (str[i] == ')')
//		{
//			int t = 0; int f = 0;
//			while (stk.top() != '(')
//			{
//				if (stk.top() == 'f')
//				{
//					f++;
//					stk.pop();
//				}
//				else if (stk.top() == 't')
//				{
//					t++;
//					stk.pop();
//				}
//			}
//			stk.pop();
//			char op = stk.top();
//			stk.pop();
//			if (op == '&')
//			{
//				if (f > 0) stk.push('f');
//				else stk.push('t');
//			}
//			else if (op == '|')
//			{
//				if (t > 0) stk.push('t');
//				else stk.push('f');
//			}
//			else if (op == '!')
//			{
//				if (t > 0)
//				{
//					stk.push('f');
//				}
//				else if (f > 0)
//				{
//					stk.push('t');
//				}
//			}
//		}
//	}
//	if (stk.top() == 't')
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//int smallestNum(string s,int k)
//{
//	char currDigit; stack<char>stk;
//	for (int i = 0; i < s.size(); i++)
//	{
//		currDigit = s[i];
//		if (!stk.empty())
//		{
//			if (k > 0)
//			{
//				if (stk.top() > currDigit)
//				{
//					while (stk.top() > currDigit)
//					{
//						stk.pop();
//						stk.push(currDigit);
//						k--;
//					}
//				}
//				else
//				{
//					stk.push(currDigit);
//				}
//			}
//		}
//		else
//		{
//			stk.push(currDigit);
//		}
//	}
//
//}
//int main()
//{
//	string s = "!(t)";
//	cout << booleanExp(s);
//	return 0;
//}