#include<iostream>
using namespace std;
void towersOfHanoi(int n, char S, char A, char D)
{
	if (n == 1)
	{
		cout << "Move disk "<< n << " from " << S << " to " << D << endl;
		return;
	}
	else
	{
		towersOfHanoi(n - 1, S, D, A);
		cout << "Move disk " << n << " from " << S << " to " << D << endl;
		towersOfHanoi(n - 1, A, S, D);
	}
}
int main()
{
	int n;
	cout << "Enter number of Disks to move: " << endl;
	cin >> n;
	towersOfHanoi(n, 'S', 'A', 'D');

}
