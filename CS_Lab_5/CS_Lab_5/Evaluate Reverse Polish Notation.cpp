//#include<iostream>
//#include<stack>
//#include<vector>
//#include<string>
//using namespace std;
//
//int evalRPN(vector<string>& tokens)
//{
//	stack<int> stk;
//	for (int i = 0; i < tokens.size(); i++)
//	{
//		if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
//		{
//			if (!stk.empty() && stk.size() >= 2)
//			{
//				int a = stk.top();
//				stk.pop();
//				int b = stk.top();
//				stk.pop();
//				if (tokens[i] == "+")
//				{
//					int res = b + a;
//					stk.push(res);
//				}
//				else if (tokens[i] == "-")
//				{
//					int res = b - a;
//					stk.push(res);
//				}
//				else if (tokens[i] == "*")
//				{
//					int res = b * a;
//					stk.push(res);
//				}
//				else if (tokens[i] == "/")
//				{
//					int res = b / a;
//					stk.push(res);
//				}
//			}
//		}
//		else
//		{
//			int operand = stoi(tokens[i]);
//			stk.push(operand);
//		}
//	}
//	return stk.empty() ? -1 : stk.top();
//	
//}
//int main()
//{
//	vector<string> s = { "10","6","9","3","+","-11","*","/","*","17","+","5","+"};
//	 cout<< evalRPN(s);
//	return 0;
//}