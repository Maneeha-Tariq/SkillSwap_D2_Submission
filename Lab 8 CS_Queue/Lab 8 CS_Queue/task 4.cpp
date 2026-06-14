#include<iostream>
#include<queue>
#include<string>
using namespace std;
struct helper
{
	int count;
	helper()
	{
		count = 0;
	}
};
string firstNonRepeatingCh(string s)
{
	queue<char>q; string res;
	helper freq[26];
	for (int i = 0; i < s.size(); i++)
	{
		freq[s[i] - 'a'].count++;
		
		q.push(s[i]);
		while (!q.empty() && freq[q.front() - 'a'].count > 1)
		{
			q.pop();
		}
		if (!q.empty())
		{
			res += q.front();
		}
		else
		{
			res += '#';
		}
	}
	return res;

}
int main()
{
	string s = "geeksforgeeks";
	string t = firstNonRepeatingCh(s);
	cout << t;
	return 0;
}