//#include<iostream>
//#include<queue>
//#include<deque>
//#include<stack>
//using namespace std;
//void interleaveQueue(queue<int>& q)
//{
//	queue<int>firstHalf;
//	queue<int>secondHalf;
//	int s = q.size() / 2;
//	for (int i = 0; i < s; i++)
//	{
//		firstHalf.push(q.front());
//		q.pop();
//	}
//	while (!q.empty())
//	{
//		secondHalf.push(q.front());
//		q.pop();
//	}
//	int i = 0;
//	while (!firstHalf.empty() && !secondHalf.empty())
//	{
//		if (i % 2 == 0)
//		{
//			q.push(firstHalf.front());
//			firstHalf.pop();
//		}
//		else if (i % 2 == 1)
//		{
//			q.push(secondHalf.front());
//			secondHalf.pop();
//		}
//		i++;
//	}
//	if (!firstHalf.empty()|| !secondHalf.empty())
//	{
//		if (!firstHalf.empty())
//		{
//			while (!firstHalf.empty())
//			{
//				q.push(firstHalf.front());
//				firstHalf.pop();
//			}
//		}
//		else
//		{
//			while (!secondHalf.empty())
//			{
//				q.push(secondHalf.front());
//				secondHalf.pop();
//			}
//		}
//	}
//}
//
//bool isPalindrome(string s)
//{
//	deque<char> q; string temp;
//	for (int i = 0; i < s.size(); i++)
//	{
//		q.push_back(s[i]);
//	}
//	while (!q.empty())
//	{
//		temp += q.back();
//		q.pop_back();
//	}
//	return s == temp ? 1 : 0;
//}
//int main()
//{
//	/*queue<int> q;
//	q.push(10);
//	q.push(20);
//	q.push(30);
//	q.push(40);
//	q.push(50);
//	q.push(60);
//	
//	interleaveQueue(q);
//	while (!q.empty())
//	{
//		cout << q.front() << " ";
//		q.pop();
//	}*/
//	string s = "madam";
//	if (isPalindrome(s))
//	{
//		cout << "String is Palindrome\n";
//	}
//	else
//	{
//		cout << "String is not palindrome\n";
//	}
//	return 0;
//
//}