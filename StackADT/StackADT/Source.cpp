#include<iostream>
#include "Stack.h"
#include<vector>
using namespace std;
vector<int> nextGreater(vector<int>& arr)
{
	Stack<int> s; Stack<int>t;

	for (int i = 0; i < arr.size(); i++)
	{
		bool exists = false;
		s.push(arr[i]);
		for (int j = i + 1; j < arr.size(); j++)
		{
			if (arr[j] > s.stackTop())
			{
				t.push(arr[j]);
				exists = true;
				break;
			}
		}
		if (!exists)
		{
			t.push(-1);
		}
	}
	vector<int> v(t.getNumberOfElements());
	for (int i = t.getNumberOfElements()-1 ; i >= 0; i--)
	{
		v[i] = t.stackTop();
		t.pop();
	}
	return v;
}
// 0(n)
vector<int> nextGreaterInNtimes(vector<int>& arr)
{
	int n = arr.size();
	vector<int>res(n, -1);
	Stack<int>s;
	for (int i = 0; i < n; i++)
	{
		while (!s.isEmpty() && arr[i] > arr[s.stackTop()])
		{
			res[s.stackTop()] = arr[i];
			s.pop();
		}
		s.push(i);
	}
	return res;
}
void Hanoi(int disk, char S, char A, char D)
{
	if (disk == 1)
	{
		cout << S << " to " << D << endl;
	}
	else
	{
		Hanoi(disk - 1, S, D, A);
		cout << S << " to " << D<< endl;
		Hanoi(disk - 1, A, S, D);
	}
}
int main()
{
	//arr = [2, 1, 5, 3, 4, 7, 6]
	/*vector<int> v;
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(7);
	v.push_back(6);
	vector<int> t = nextGreaterInNtimes(v);
	for (int i = 0; i < t.size(); i++)
	{
		cout << t[i] << " ";
	}*/
	/*Stack<int> s;
	s.push(10);
	s.push(20);
	s.push(39);
	int n = s.getNumberOfElements();
	cout << n<< "\n";
	s.pop();
	cout << s.getNumberOfElements();
	cout << "\n"<< s.isEmpty();
	cout << "\n";
	cout << s.isFull();
	cout << "\n";
	cout << s.getCapacity();*/
	char s ='S';
	char a = 'A';
	char d = 'D';
	Hanoi(5, s, a, d);
	
}