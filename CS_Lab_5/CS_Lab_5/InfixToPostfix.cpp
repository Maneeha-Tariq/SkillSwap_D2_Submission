#include <iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperator(char c)
{
	return c == '+' || c == '-' || c == '/' || c == '^' || c == '*';
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
				(precedence(stk.top()) == precedence(infix[i]) && infix[i] != '^'&& infix[i]!='=')))
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
string infixToPrefix(string& infix)
{
	reverse(infix.begin(),infix.end());
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
		}
		else if (infix[i] == ')')
		{
			infix[i] = '(';
		}
	}
	string s = infixToPostfix(infix);
	reverse(s.begin(), s.end());
	return s;
}

//manually using stack isme simply hamne phle infix string ko right to left scan krna ha means phle reverse krdein g then us expression
// ko stack k through postfix m convert hojay  g then reverse krde g usy ham jb ) brcket ay g to stack p push kre g or agr (ay g to pop jab tk 
// ) ni ata operators pop krke string k sth attach krdein g same whi kam ha infix to postfix wala
string infixToPrefix2(string& infix)
{
	string str; stack<char>stk;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.size(); i++)
	{
		if (infix[i] == ')')
		{
			stk.push(infix[i]);
		}
		else if (isOperator(infix[i]))
		{
			if (!stk.empty() && isOperator(stk.top()))
			{
				while (!stk.empty() && (precedence(stk.top()) > precedence(infix[i])
				|| (precedence(stk.top()) == precedence(infix[i]) && infix[i]!='^' && infix[i]!='=')))
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
		else if (infix[i] == '(')
		{
			while (!stk.empty() && stk.top() != ')')
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
	reverse(str.begin(), str.end());
	return str;
}
string postfixToInfix(string& postfix)
{
	stack<string>stk;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (!isOperator(postfix[i]))
		{
			stk.push(string(1, postfix[i]));
		}
		else
		{
			if (stk.size() < 2) return " ";
			string t1 = stk.top();
			stk.pop();
			string t2 = stk.top();
			stk.pop();
			stk.push("(" + t2 + postfix[i] + t1 + ")");
		}
	}
	return stk.top();
}
string prefixToInfix(string& prefix)
{
	stack<string>stk;
	for (int i = prefix.size()-1; i >= 0; i--)
	{
		if (!isOperator(prefix[i]))
		{
			stk.push(string(1, prefix[i]));
		}
		else
		{
			if (stk.size() < 2) return " ";
			string t1 = stk.top();
			stk.pop();
			string t2 = stk.top();
			stk.pop();
			stk.push("(" + t1 + prefix[i] + t2 + ")");
		}
	}
	return stk.top();
}
string postfixToPrefix(string& postfix)
{
	stack<string>stk;
	for (int i = 0; i < postfix.size(); i++)
	{
		if (!isOperator(postfix[i]))
		{
			stk.push(string(1, postfix[i]));
		}
		else
		{
			if (stk.size() < 2) return " ";
			string t1 = stk.top();
			stk.pop();
			string t2 = stk.top();
			stk.pop();
			stk.push( postfix[i] + t2 + t1);
		}
	}
	return stk.top();
}
string prefixToPostfix(string& prefix)
{
	stack<string>stk;
	for (int i = prefix.size() - 1; i >= 0; i--)
	{
		if (!isOperator(prefix[i]))
		{
			stk.push(string(1, prefix[i]));
		}
		else
		{
			if (stk.size() < 2) return " ";
			string t1 = stk.top();
			stk.pop();
			string t2 = stk.top();
			stk.pop();
			stk.push(t1+t2+prefix[i]);
		}
	}
	return stk.top();
}
int main()
{
	//(A + B)* (C - D)
	//*+AB - CD
	//AB+CD-*
	string s = "A^B^C";
	cout << infixToPostfix(s);

	return 0;
}
