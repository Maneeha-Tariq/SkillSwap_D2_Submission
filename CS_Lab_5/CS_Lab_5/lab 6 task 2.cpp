#include<iostream>
#include<stack>
#include<string>
using namespace std;
bool booleanExp(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == ',') continue;
		if (s[i] == '(' || s[i] == '&' || s[i] == '|' || s[i] == '!' || s[i] == 'f' || s[i] == 't')
		{
			stk.push(s[i]);
		}
		else
		{
			int f = 0; int t = 0;
			while (!stk.empty() && stk.top() != '(')
			{
				if (stk.top() == 'f')
				{
					stk.pop();
					f++;
				}
				else if (stk.top() == 't')
				{
					stk.pop(); 
					t++;
				}
			}
			stk.pop();

			if (stk.top() == '&')
			{
				if (f > 0)
				{
					stk.pop();
					stk.push('f');
				}
				else
				{
					stk.pop();
					stk.push('t');
				}
			}
			else if (stk.top() == '|')
			{
				if (t > 0)
				{
					stk.pop();
					stk.push('t');
				}
				else
				{
					stk.pop();
					stk.push('f');
				}
			}
			else if (stk.top() == '!')
			{
				if (t > 0)
				{
					stk.pop();
					stk.push('f');
				}
				else
				{
					stk.pop();
					stk.push('t');
				}
			}
		}
	}
	return stk.top() == 't' ? true : false;
}
int main()
{
	string s = "!(&(f,t))";
	bool t =  booleanExp(s);
	if (!t)
	{
		cout << "false";
	}
	else
	{
		cout << "true";
	}
	return 0;
}