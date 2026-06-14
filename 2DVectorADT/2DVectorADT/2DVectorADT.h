#ifndef Vector2D_H
#define Vector2D_H
#include <iostream>
using namespace std;
class Vector2D
{
	int noOfRows;
	int noOfCols;
	int currRow;
	int currCol;
	int** data;
public:

	Vector2D(int r, int c)
	{
		noOfRows = r;
		noOfCols = c;
		currRow = 0;
		currCol = 1;
		data = new int* [noOfRows];
		for (int i = 0; i < noOfRows; i++)
		{
			data[i] = new int[noOfCols];
		}
		for (int i = 0; i < noOfRows; i++)
		{
			for (int j = 0; j < noOfCols; j++)
			{
				data[i][j] = 0;
			}
		}
	}
	void pushBack(int value)
	{
		if (currRow >= noOfRows)
		{
			return;
		}

		if (currRow % 2 == 0 && currCol % 2 != 0 && currRow < noOfRows && currCol < noOfCols)
		{
			data[currRow][currCol] = value;
		}
		currCol += 2;
		if (currCol >= noOfCols)
		{
			currCol = 1;
			currRow += 2;
		}
	}
	void display()
	{
		for (int i = 0; i < noOfRows; i++)
		{
			for (int j = 0; j < noOfCols; j++)
			{
				cout << data[i][j] << '\t';
			}
			cout << endl;
		}
	}
	~Vector2D()
	{
		for (int i = 0; i < noOfRows; i++)
		{
			delete[] data[i];
		}

		delete[] data;
	}
};
#endif
