#include<iostream>
#include<stack>
#include<vector>
#include<string>
using namespace std;
int vars[26];
bool validParenthesis(string s)
{
	stack<char>stk;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			stk.push(s[i]);
		}
		else if (s[i] == ')')
		{
			if (stk.empty()) return false;
			stk.pop();
		}
	}
	return stk.empty() ? 1 : 0;
}
bool isOperand(char c)
{
	return c >= 'a' && c <= 'z' ? 1 : 0;
}
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '*' || c == '/'||c == '^';
}
bool isFullyParenthesis(string s)
{
	bool exp = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != '(' && s[i] != ')')
		{
			exp = true;
		}
	}
	return exp == true ? 0 : 1;
}
bool consecutiveOperators(string s)
{
	for (int i = 0; i < s.size()-1; i++)
	{
		if (isOperator(s[i]) && isOperator(s[i + 1]))
		{
			return true;
		}
	}
	return false;
}
bool consecutiveOperands(string s)
{
	for (int i = 0; i < s.size()-1; i++)
	{
		if (isOperand(s[i]) && isOperand(s[i + 1]))
		{
			return true;
		}
	}
	return false;
}
int precedence(char c)
{
	if (c == '^')
	{
		return 3;
	}
	else if (c == '*' || c == '/')
	{
		return 2;
	}
	else if (c == '+' || c == '-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
string infixToPostfix(string& infix)
{
	string str; stack<char>stk;
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			stk.push(infix[i]);
		}
		else if (isOperator(infix[i]))
		{
			if (!stk.empty() && isOperator(stk.top()))
			{
				while (!stk.empty() && (precedence(stk.top()) > precedence(infix[i]) ||
					(precedence(stk.top()) == precedence(infix[i]) && infix[i] != '^')))
				{
					str += stk.top();
					stk.pop();
				}
				stk.push(infix[i]);
			}
			else
			{
				stk.push(infix[i]);
			}
		}
		else if (infix[i] == ')')
		{
			while (!stk.empty() && stk.top() != '(')
			{
				str += stk.top();
				stk.pop();
			}
			stk.pop();
		}
		else
		{
			str += infix[i];
		}
	}
	while (!stk.empty())
	{
		str += stk.top();
		stk.pop();
	}
	return str;
}
bool isDigit(char c)
{
	return c >= '0' && c <= '9' ? 1 : 0;
}
int intPow(int base, int exp)
{
	int res = 1;
	for (int i = 0; i < exp; i++) res *= base;
	return res;
}
bool validate(string s)
{
	if (validParenthesis(s) && !isOperator(s[0]) && !isOperator(s[s.size() - 1]) &&
	!isFullyParenthesis(s) && !consecutiveOperators(s) && !consecutiveOperands(s))
	{
		return true;
	}
	else
	{
		return false;
	}
}
vector<char> toPostfix(string s)
{
	if (validate(s))
	{
		string str = infixToPostfix(s);
		vector<char>v(str.size());
		for (int i = 0; i < str.size(); i++)
		{
			v[i] = str[i];
		}
		return v;
	}
	else
	{
		return vector<char>();
	}
}
bool evalPostfix(vector<char>pf, int& result)
{
	 stack<int>operand;
	for (int i = 0; i < pf.size(); i++)
	{
		if (isOperator(pf[i]))
		{
			char c = pf[i];
			if (operand.size() < 2)
			{
				return false;
			}
			int a = operand.top();
			operand.pop();
			int b = operand.top();
			operand.pop();
			if (c == '*')
			{
				int res = b * a;
				operand.push(res);
			}
			else if (c == '+')
			{
				int res = b + a;
				operand.push(res);
			}
			else if (c == '/')
			{
				if (a == 0)
				{
					cout << "INVALID";
					return false;
				}
				int res = b / a;
				operand.push(res);
			}
			else if (c == '^')
			{
				int res = intPow(b, a);
				operand.push(res);
			}
			else
			{
				int res = b - a;
				operand.push(res);
			}
		}
		else
		{
			operand.push(vars[pf[i] - 'a']);
		}
	}
	if (operand.size() != 1)
	{
		return false;
	}
	result = operand.top();
	return true;
}
int main()
{
	for (int i = 0; i < 26; i++)
	{
		vars[i] = i + 1;
	}
	string s = "(a+b)*(c-d)+e^f";
	int result;
	int n;
	cout << "Enter number of queries you want to execute: ";
	cin >> n;
	char c; char modify;
	int L; int R; int val;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (c == 'E')
		{
			cin >> L >> R;
			if (L < 0 || R >= s.size() || L > R) {
				cout << "INVALID\n";
				continue;
			}
			string str;
			for (int i = L; i <= R; i++)
			{
				str += s[i];
			}
			vector<char> v = toPostfix(str);
			if (v.empty())
			{
				cout << "INVALID\n";
				continue;
			}
			bool t = evalPostfix(v, result);
			if (!t)
			{
				cout << "INVALID\n";
				continue;
			}
			else
			{
				cout << "Result: " << result;
			}
			cout << "\n";
		}
		else if (c == 'U')
		{
			cin >> modify;
			cin >> val;
			vars[modify - 'a'] = val;
			cout << "\n";
		}
	}
	return 0;
}