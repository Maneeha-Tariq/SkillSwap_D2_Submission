#include<iostream>
#include<stack>
#include<string>
#include<iostream>
using namespace std;
string removeKDigits(string s,int k)
{
	stack<char> stk; string str;
	for (int i = 0; i < s.size(); i++)
	{
		if (stk.empty())
		{
			stk.push(s[i]);
		}
		else
		{
			while (!stk.empty() && stk.top() > s[i] && k > 0)
			{
				stk.pop();
				k--;
			}
			stk.push(s[i]);
		}
	}
	if (k > 0)
	{
		while (!stk.empty() && k > 0)
		{
			stk.pop();
			k--;
		}
	}
	while (!stk.empty())
	{
		str += stk.top();
		stk.pop();
	}
	if (!str.empty())
	{
		reverse(str.begin(), str.end());
	}
	int i = 0;
	while (i < str.size() && str[i] == '0')
	{
		i++;
	}
	str = str.substr(i);
	return str.empty() ? "0" : str;

}
int main()
{
	string s = "10";
	cout<< removeKDigits(s, 2);
}