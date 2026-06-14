#include<iostream>
#include<queue>
#include<vector>
using namespace std;
struct helper
{
	int num;
	int den;
	double fraction;
};
vector<int> kthSmallestFraction(vector<int>& v,int k)
{
	helper h ;
	vector<int>temp(2);
	priority_queue<
		pair<double, pair<int,int>>,
		vector<pair<double, pair<int,int>>>, 
		greater<pair<double, pair<int,int>>>
		>q;
	for (int i = 0; i < v.size(); i++)
	{
		int n = v[i];
		for (int j = i+1; j < v.size(); j++)
		{
			double frac = (double)n / v[j];
			h.num = n;
			h.den = v[j];
			h.fraction = frac;
			q.push({ h.fraction,{h.num,h.den} });
		}
	}
	for (int i = 0; i < k-1; i++)
	{
		q.pop();
	}
	temp[0] = q.top().second.first;
	temp[1] = q.top().second.second;
	return temp;
}
struct Temp
{
	int numerator;
	int denominator;
	Temp()
	{
		numerator = 0;
		denominator = 0;
	}
};
vector<int> KthSmallest(vector<int>& v, int k)
{
	vector<int>tem(2);
	priority_queue<double, vector<double>, greater<double>>pq;
	queue<Temp>t;
	for (int i = 0; i < v.size(); i++)
	{
		int n = v[i];
		for (int j = i + 1; j < v.size(); j++)
		{
			double frac = n / (double)v[j];
			pq.push(frac);
			
		}
	}
}
int main()
{
	vector<int>v = { 1,7};
	vector<int>t = kthSmallestFraction(v, 1);
	cout << "["<< t[0]<< ", "<< t[1]<< "]";
	
	return 0;
}