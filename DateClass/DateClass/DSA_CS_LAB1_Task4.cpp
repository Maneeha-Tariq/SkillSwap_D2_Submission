#include<iostream>
using namespace std;
int main()
{
	int n;
	cout << "Enter n: ";
	cin >> n;
	int j = 3, odd = 5;
	cout << j << endl;
	for (int i = 1; i < n; i++)
	{
		j = j + odd;
		cout << j << endl;
		odd = odd + 2;
	}
	return 0;
}