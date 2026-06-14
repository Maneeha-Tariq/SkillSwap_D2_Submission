//BSEF24M046
#include "String.h"
#include <iostream>
#include <initializer_list>
#include<fstream>
using namespace std;
template <typename T>
class Array
{
	T* data;
	int size;
	bool isValidIndex(int index) const
	{
		return (index >= 0 && index < size);

	}
public:
	Array()
	{
		data = nullptr;
		size = 0;
	}
	Array(int s) :Array()
	{
		if (s > 0)
		{
			data = new T[s];
			size = s;
		}
	}
	Array(const Array& r) :Array()
	{
		if (r.size <= 0)
			return;
		size = r.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = r.data[i];
		}
	}
	Array<T>& operator=(const Array<T>& r)
	{
		if (r.size == 0)
		{
			this->~Array();
			return *this;
		}
		if (this == &r)
			return *this;
		this->~Array();
		size = r.size;
		data = new T[size];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = r.data[i];
		}
		return *this;
	}
	Array(Array<T>&& other) :Array()
	{
		data = other.data;
		size = other.size;
		other.data = nullptr;
		other.size = 0;
	}
	Array<T>& operator=(Array<T>&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] data;

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;

		return *this;
	}
	const T& operator [](int index) const
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			cout << "Index out of bound";
			exit(0);
		}
	}
	T& operator [](int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			cout << "Index out of bound";
			exit(0);
		}
	}
	int getSize() const
	{
		return size;
	}
	void reSize(int s)
	{
		if (s <= 0)
		{
			this->~Array();
			return;
		}
		T* temp = new T[s];
		int i = 0;
		while (i < size && i < s)
		{
			temp[i] = data[i];
			i++;
		}
		this->~Array();
		data = temp;
		size = s;
	}
	~Array()
	{
		if (data)
		{
			delete[]data;
			data = nullptr;
		}
		size = 0;
	}
	Array(initializer_list<T> val) :Array()
	{
		size = val.size();
		if (size == 0)
			return;
		data = new T[size];
		int i = 0;
		for (auto x : val)
		{
			data[i] = x;
			i++;
		}
	}
	const T* begin()
	{
		return &data[0];
	}
	const T* end()
	{
		return &data[size];
	}
};
template <typename T>
ostream& operator <<(ostream& out, const Array<T>& r)
{
	out << "{";
	for (int i = 0; i < r.getSize(); i++)
	{
		out << r[i];
		if (i < r.getSize() - 1)
		{
			out << " , ";
		}
	}
	out << "}";
	return out;
}
template <typename T>
istream& operator >>(istream& out, Array<T>& r)
{
	for (int i = 0; i < r.getSize(); i++)
	{
		out >> r[i];
	}
	return out;
}
bool wordSearch(Array<Array<char>> & grid,String word)
{
	String s;
	int t = 0,r=0,n=0;
	int dR[] = { 0,0,1,-1,1,1,-1,-1 };
	int dC[] = { 1,-1,0,0,1,-1,1,-1 };
	for (int i = dR[t++]; i < grid.getSize(); i++)
	{
		for (int j = dC[r++]; j < grid[i].getSize(); j++)
		{
			if (grid[i][j] == word[n++])
			{
				s += grid[i][j];
			}
			else
			{
				r++;
			}
		}
	}
	if (s.compare(word) == 0)
	{
		cout << "Found( " << t << r << ")";
		return true;
	}
	return false;

}
int tom(int n)
{
	if (n > 100)
	{
		return n - 10;
	}
	else
	{
		return tom(tom(n + 11));
	}
}
void reverseArray(int* arr, int n)
{
	int i = 0;
	if (n <=0)
	{
		return;
	}
	int temp = arr[i];
	arr[i++] = arr[n - 1];
	arr[n - 1] = temp;

	reverseArray(arr+1, n - 2);

}
int main()
{
	int arr[4] = { 1,2,3,4 };
	reverseArray(arr, 4);
	for (int i = 0; i < 4; i++)
	{
		cout << arr[i] << " ";
	}
}