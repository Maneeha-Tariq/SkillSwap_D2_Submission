#include<iostream>
using namespace std;
enum ArrayMapping{ROW_MAJOR,COLUMN_MAJOR};
void printND(int N, ArrayMapping mapping = ROW_MAJOR)
{
	if (mapping == ROW_MAJOR)
	{
		for (int i = 0; i < N; i++)
		{
			cout << "I" << i + 1;
			for (int j = i + 1; j < N; j++)
			{
				cout << "*D" << j + 1;
			}
			if (i != N - 1)
			{
				cout << " + ";
			}
		}
	}
	else if (mapping == COLUMN_MAJOR)
	{
		for (int i = N; i >0; i--)
		{
			cout << "I" << i ;
			for (int j = i -1; j > 0; j--)
			{
				cout << "*D" << j ;
			}
			if (i != 1)
			{
				cout << " + ";
			}
		}
	}
}
int main()
{
	printND(2,ROW_MAJOR);
}

