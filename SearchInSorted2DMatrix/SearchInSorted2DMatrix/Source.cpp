#include<iostream>
#include<vector>
using namespace std;
// last element of row is less than or equal to next row ka first element
bool searchGlobalSorted(vector<vector<int>>& v,int k)
{
	int m = v.size();
	int n = v[0].size();
	int low = 0;
	int high = (m * n) - 1;
	while (low <= high)
	{
		int mid = low + (high - low) / 2;
		int row = mid / n;
		int col = mid % n;
		if (v[row][col] == k)
		{
			return true;
		}
		else if (v[row][col] < k)
		{
			low = mid + 1;
		}
		else if (v[row][col] > k)
		{
			high = mid - 1;
		}

	}
	return false;
}
int main()
{
	/*int m;
	cout << "Enter no of rows: ";
	cin >> m;
	int n;
	cout << "Enter no of cols: ";
	cin >> n;
	vector<vector<int>>v(m,vector<int>(n));

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> v[i][j];
		}
	}*/
	vector<vector<int>> mat = {
	   {1, 3, 5},
	   {7, 9, 11},
	   {13, 15, 17}
	};
	cout << searchGlobalSorted(mat,8);
	


	return 0;
}