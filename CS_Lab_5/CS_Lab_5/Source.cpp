//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//bool isValidstringBracket(string str)
//{
//	stack<char> stk;
//	int i = 0;
//	
//	while (str[i] != '\0')
//	{
//		if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//		{
//			stk.push(str[i]);
//		}
//		else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
//		{
//			if (stk.top() =='('&& str[i]==')')
//			{
//				stk.pop();
//			}
//			else if (stk.top() == '{' && str[i] == '}')
//			{
//				stk.pop();
//			}
//			else if (stk.top() == '[' && str[i] == ']')
//			{
//				stk.pop();
//			}
//		}
//		i++;
//	}
//	if (stk.empty())
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//int BracketScoring(string str)
//{
//	if (!isValidstringBracket(str))
//	{
//		cout << "INVALID";
//		exit(0);
//	}
//	int depth = 0;
//	int score;
//	int result = 0;
//	stack<char> stk;
//	if (isValidstringBracket(str))
//	{
//		int i = 0;
//		while (str[i] != '\0')
//		{
//			if (str[i] == '(' || str[i] == '{' || str[i] == '[')
//			{
//				stk.push(str[i]);
//				depth++;
//			}
//			else if (str[i] == ')' || str[i] == '}' || str[i] == ']')
//			{
//				if (stk.top() == '(' && str[i] == ')')
//				{
//					score = 1* depth;
//					result += score;
//					stk.pop();
//				}
//				else if (stk.top() == '{' && str[i] == '}')
//				{
//					score = 3 * depth;
//					result += score;
//					stk.pop();
//				}
//				else if (stk.top() == '[' && str[i] == ']')
//				{
//					score = 2 * depth;
//					result += score;
//					stk.pop();
//				}
//				depth--;
//			}
//			i++;
//		}
//	}
//	return result;
//}
//int main()
//{
//	string s = "({[()]})";
//	int d = BracketScoring(s);
//	cout << d;
//	
//	return 0;
//}