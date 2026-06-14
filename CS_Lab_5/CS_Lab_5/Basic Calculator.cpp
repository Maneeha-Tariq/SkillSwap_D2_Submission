//#include<iostream>
//#include<stack>
//#include<string>
//using namespace std;
//bool isOperator(char c)
//{
//	return c == '*' || c == '+' || c == '-' || c == '/';
//}
//int precedence(char c)
//{
//	if (c == '*' || c == '/')
//	{
//		return 2;
//	}
//	else if (c == '-' || c == '+')
//	{
//		return 1;
//	}
//	else
//	{
//		return 0;
//	}
//}
//bool isDigit(char c)
//{
//	return c =='0'||c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
//    || c == '6' || c == '7' || c == '8' || c == '9';
//}
//int calculate(string s)
//{
//	stack<char>oper; stack<int>operand;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ' ') continue;
//		if (isOperator(s[i]))
//		{
//			if (oper.empty())
//			{
//				oper.push(s[i]);
//			}
//			else
//			{
//				while (!oper.empty() && precedence(oper.top()) >= precedence(s[i]))
//				{
//					char c = oper.top();
//					if (!operand.empty() && operand.size() >= 2)
//					{
//						int a = operand.top();
//						operand.pop();
//						int b = operand.top();
//						operand.pop();
//						if (c == '*')
//						{
//							int res = b * a;
//							operand.push(res);
//						}
//						else if (c == '+')
//						{
//							int res = b + a;
//							operand.push(res);
//						}
//						else if (c == '/')
//						{
//							int res = b / a;
//							operand.push(res);
//						}
//						else
//						{
//							int res = b - a;
//							operand.push(res);
//						}
//					}
//					oper.pop();
//				}
//				oper.push(s[i]);
//			}
//		}
//		else
//		{
//			int num = 0;
//			int j = i;
//			while (j < s.size() && isDigit(s[j]))
//			{
//				num = num * 10 + (s[j] - '0');
//				j++;
//			}
//			operand.push(num);
//			i = j - 1;
//		}
//	}
//	while (!oper.empty())
//	{
//		char c = oper.top();
//		if (!operand.empty() && operand.size() >= 2)
//		{
//			int a = operand.top();
//			operand.pop();
//			int b = operand.top();
//			operand.pop();
//			if (c == '*')
//			{
//				int res = b * a;
//				operand.push(res);
//			}
//			else if (c == '+')
//			{
//				int res = b + a;
//				operand.push(res);
//			}
//			else if (c == '/')
//			{
//				int res = b / a;
//				operand.push(res);
//			}
//			else
//			{
//				int res = b - a;
//				operand.push(res);
//			}
//		}
//		oper.pop();
//	}
//	return operand.empty() ? -1 : operand.top();
//}
//
//int main()
//{
//	string s = " 12+2*2";
//	cout << calculate(s);
//	return 0;
//}
