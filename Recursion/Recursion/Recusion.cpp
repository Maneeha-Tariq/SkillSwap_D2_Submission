#include <iostream>
#include "String.h"
//#include<fstream>
//template <typename T>
//class Array
//{
//	T* data;
//	int size;
//	bool isValidIndex(int index) const
//	{
//		return (index >= 0 && index < size);
//
//	}
//public:
//	Array()
//	{
//		data = nullptr;
//		size = 0;
//	}
//	Array(int s) :Array()
//	{
//		if (s > 0)
//		{
//			data = new T[s];
//			size = s;
//		}
//	}
//	Array(const Array& r) :Array()
//	{
//		if (r.size <= 0)
//			return;
//		size = r.size;
//		data = new T[size];
//		for (int i = 0; i < size; i++)
//		{
//			data[i] = r.data[i];
//		}
//	}
//	Array<T>& operator=(const Array<T>& r)
//	{
//		if (r.size == 0)
//		{
//			this->~Array();
//			return *this;
//		}
//		if (this == &r)
//			return *this;
//		this->~Array();
//		size = r.size;
//		data = new T[size];
//		int i;
//		for (i = 0; i < size; i++)
//		{
//			data[i] = r.data[i];
//		}
//		return *this;
//	}
//	Array(Array<T>&& other) :Array()
//	{
//		data = other.data;
//		size = other.size;
//		other.data = nullptr;
//		other.size = 0;
//	}
//	Array<T>& operator=(Array<T>&& other)
//	{
//		if (this == &other)
//		{
//			return *this;
//		}
//		delete[] data;
//
//		data = other.data;
//		size = other.size;
//
//		other.data = nullptr;
//		other.size = 0;
//
//		return *this;
//	}
//	const T& operator [](int index) const
//	{
//		if (isValidIndex(index))
//		{
//			return data[index];
//		}
//		else
//		{
//			cout << "Index out of bound";
//			exit(0);
//		}
//	}
//	T& operator [](int index)
//	{
//		if (isValidIndex(index))
//		{
//			return data[index];
//		}
//		else
//		{
//			cout << "Index out of bound";
//			exit(0);
//		}
//	}
//	int getSize() const
//	{
//		return size;
//	}
//	void reSize(int s)
//	{
//		if (s <= 0)
//		{
//			this->~Array();
//			return;
//		}
//		T* temp = new T[s];
//		int i = 0;
//		while (i < size && i < s)
//		{
//			temp[i] = data[i];
//			i++;
//		}
//		this->~Array();
//		data = temp;
//		size = s;
//	}
//	~Array()
//	{
//		if (data)
//		{
//			delete[]data;
//			data = nullptr;
//		}
//		size = 0;
//	}
//	Array(initializer_list<T> val) :Array()
//	{
//		size = val.size();
//		if (size == 0)
//			return;
//		data = new T[size];
//		int i = 0;
//		for (auto x : val)
//		{
//			data[i] = x;
//			i++;
//		}
//	}
//	const T* begin()
//	{
//		return &data[0];
//	}
//	const T* end()
//	{
//		return &data[size];
//	}
//};
//template <typename T>
//ostream& operator <<(ostream& out, const Array<T>& r)
//{
//	out << "{";
//	for (int i = 0; i < r.getSize(); i++)
//	{
//		out << r[i];
//		if (i < r.getSize() - 1)
//		{
//			out << " , ";
//		}
//	}
//	out << "}";
//	return out;
//}
//template <typename T>
//istream& operator >>(istream& out, Array<T>& r)
//{
//	for (int i = 0; i < r.getSize(); i++)
//	{
//		out >> r[i];
//	}
//	return out;
//}
//
//using namespace std;
//int sumUpTo(int n)
//{
//	if (n <= 0)
//	{
//		return 0;
//	}
//	else
//	{
//		return n + sumUpTo(n - 1);
//	}
//}
//int sumOfDigits(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	return (n % 10) + sumOfDigits(n / 10);
//}
//void printSquares(int n)
//{
//	if (n == 1)
//	{
//		cout << "1";
//		return;
//	}
//	if (n % 2!= 0)
//	{
//		cout << n * n << ",";
//		printSquares(n - 1);
//	}
//	else if (n % 2 == 0)
//	{
//		printSquares(n - 1);
//		cout << "," << n * n;
//	}
//}
int evenDigits(int n)
{
	if (n == 0)
	{
		return 0;
	}
	if ((n % 10) % 2 == 0)
	{
		return  evenDigits(n / 10)*10 + (n%10);
	}
	else
	{
		return evenDigits(n / 10);
	}
}
//void reverseLines(ifstream & input)
//{
//    String line;
//	if (input.peek() == EOF)  return;
//	char ch;
//	while (input.get(ch))
//	{
//		if (ch == '\n')
//		{
//			break;
//		}
//		line += ch;
//	}
//	reverseLines(input);
//	cout << line<< '\n';
//
//}
//void pronounce(long int n)
//{
//	if (n < 20)
//	{
//		Array<String> units = { "zero","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","eighteen","nineteen" };
//		cout << units[n];
//		return;
//	}
//	else if (n % 10 == 0 && n < 100)
//	{
//		Array<String> tens = { " ","ten","twenty","thirty","forty","fifty","sixty","seventy","eighty","ninety" };
//		cout << tens[n / 10];
//	}
//	else if (n < 100)
//	{
//		pronounce(n - (n % 10));
//		cout << '-';
//		pronounce(n % 10);
//	}
//	else if (n % 100 == 0 && n < 1000)
//	{
//		pronounce(n / 100);
//		cout << " hundred";
//	}
//	else if (n < 1000)
//	{
//		pronounce(n - (n % 100));
//		cout << " ";
//		pronounce(n % 100);
//	}
//	else if (n < 1000000)
//	{
//		pronounce(n / 1000);
//		cout << " thousand";
//		if (n % 1000 != 0)
//		{
//			cout << " ";
//			pronounce(n % 1000);
//		}
//	}
//	else if (n < 1000000000)
//	{
//		pronounce(n / 1000000);
//		cout << " million";
//		if (n % 1000000 != 0)
//		{
//			cout << " ";
//			pronounce(n % 1000000);
//		}
//	}
//	else
//	{
//		pronounce(n / 1000000000);
//		cout << " billion";
//		if ((int)n % 1000000000 != 0)
//		{
//			cout << " ";
//			pronounce(n % 1000000000);
//		}
//	}
//}
//int explore(Array<Array<char>>& a, int i, int j)
//{
//	if (a[i][j] != 'w') return 0;
//	int cnt = 1;
//	a[i][j] = 't';
//	
//	if (i - 1 >= 0 && a[i - 1][j] == 'w')
//	{
//		cnt += explore(a, i - 1, j);
//	}
//	if (j+1 <a[0].getSize() && a[i][j+1] == 'w')
//	{
//		cnt += explore(a, i , j+1);
//	}
//	if (j - 1 >= 0 && a[i][j-1] == 'w')
//	{
//		cnt += explore(a, i , j-1);
//	}
//	if (i + 1 < a.getSize() && a[i+1][j] == 'w')
//	{
//		cnt += explore(a, i+1, j);
//	}
//	return cnt;
//}
//bool checkExplore(Array<Array<char>>& a, int i, int j)
//{
//	if (i < 0 || j < 0 || i >= a.getSize() || j >= a[0].getSize())
//		return 0;
//
//	if (a[i][j] != 'w')
//		return 0;
//
//	// mark visited
//	a[i][j] = 't';
//
//	// explore in 4 directions
//	// agar kisi direction me bhi white cell milta hai → return 1
//	if ((i - 1 >= 0 && checkExplore(a, i - 1, j)) ||
//		(i + 1 < a.getSize() && checkExplore(a, i + 1, j)) ||
//		(j - 1 >= 0 && checkExplore(a, i, j - 1)) ||
//		(j + 1 < a[0].getSize() && checkExplore(a, i, j + 1)))
//	{
//		return 1;  // ✅ path exists
//	}
//
//	// agar koi aur white cell nahi mila to bhi ek path count karo
//	return 1;
//}
//bool isMeasurable(int target, int* weights, int N)
//{
//
//	if (target == 0)
//	{
//		return true;
//	}
//	if (N == 0)
//	{
//		return false;
//	}
//
//	int w = weights[N - 1];
//	return (
//		isMeasurable(target, weights, N - 1) ||        // don't use this weight
//		isMeasurable(target - w, weights, N - 1) ||    // put weight on opposite side
//		isMeasurable(target + w, weights, N - 1));     // put weight on same side
//}
//int countPaths(Array<Array<char>>& a, int i, int j)
//{
//	int n = a.getSize();
//	int m = a[0].getSize();
//
//	if (i < 0 || j < 0 || i >= n || j >= m)
//		return 0;
//
//	if (a[i][j] != 'w')
//		return 0;
//
//	if (i == n - 1 && j == m - 1)
//		return 1;
//
//	a[i][j] = 't';
//
//	int total = 0;
//	total += countPaths(a, i + 1, j);
//	total += countPaths(a, i - 1, j);
//	total += countPaths(a, i, j + 1);
//	total += countPaths(a, i, j - 1);
//
//	a[i][j] = 'w'; // unmark for backtracking
//
//	return total;
//}
//int largestPath(Array<Array<char>>& a, int i, int j)
//{
//	if (i < 0 || j < 0 || i >= a.getSize() || j >= a[0].getSize() || a[i][j] != 'w')
//		return 0;
//	a[i][j] = 't';
//	return 1 + largestPath(a, i + 1, j) + largestPath(a, i - 1, j) + largestPath(a, i, j + 1) + largestPath(a, i, j - 1);
//}
//
//int main() {
//	Array<Array<char>> a = {
//		{'w','b','w'},
//		{'w','w','b'},
//		{'b','w','w'}
//	};
//	int maxSize = 0;
//	for (int i = 0; i < a.getSize(); i++)
//		for (int j = 0; j < a[0].getSize(); j++)
//			if (a[i][j] == 'w')
//				maxSize = max(maxSize, largestPath(a, i, j));
//	cout << "Largest white area size: " << maxSize;
//}
//int main() {
//	Array<Array<char>> a = {
//		{'w','b','w'},
//		{'w','w','b'},
//		{'b','w','w'}
//	};
//
//	int minSize = 1000; // large number for smallest
//	int n = a.getSize();
//	int m = a[0].getSize();
//
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j < m; j++)
//			if (a[i][j] == 'w') {
//				int sz = explore(a, i, j);
//				if (sz > 0 && sz < minSize)
//					minSize = sz;
//			}
//
//	cout << "Smallest white area size: " << minSize << endl;
//
//	return 0;
//}
//
////int main()
////{
////	Array<Array<char>> arr = { {'b','w','b','b','w'},{'w','w','b','w','w'},{'b','b','w','b','b'},{'w','b','w', 'w','w'} };
////	/*Array<Array<char>> arr = { {'b','b','b','b','b'},{'b','b','b','b','b'},{'b','b','b','b','b'},{'b','b','b', 'b','b'} };*/
////	// white areas
////	/*int count = 0;
////	for (int i = 0; i < arr.getSize(); i++)
////	{
////		for (int j = 0; j < arr[0].getSize(); j++)
////		{
////			if (arr[i][j] == 'w')
////			{
////				cout << "Size of island: " << explore(arr, i, j) << '\n';
////				count++;
////			}
////		}
////	}
////	cout << "\nno of islands in matrix: " << count;*/
////
////	// 1 or 0 if path exists or not
////	/*int count = 0;
////	bool pathFound = false;
////
////	for (int i = 0; i < arr.getSize(); i++)
////	{
////		for (int j = 0; j < arr[0].getSize(); j++)
////		{
////			if (arr[i][j] == 'w')
////			{
////				int result = checkExplore(arr, i, j);
////				count++;
////				if (result == 1)
////					pathFound = true;
////			}
////		}
////	}
////
////	cout << "\nNo of islands in matrix: " << count << endl;
////	if (pathFound)
////		cout << "Path exists between white cells.\n";
////	else
////		cout << "No path exists.\n";*/
////
////
////	/*int arr[2] = { 3,3 };
////	int* w = arr ;
////	cout << isMeasurable(8, w, 2);*/
////
////
////	cout << "Total paths from (0,0) to (end): " << countPaths(arr, 0, 0);
////
////	return 0;
////}
//
//// ENTIRE FILE REVERSE CHAR BY CHAR
////if (input.peek() == EOF) return;
////char c;
////input.get(c);
////reverseLines(input);
////cout << c;

int DMSum(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n;
	}
	int digit,num = n%10;
	while (n != 0)
	{
		digit = n % 10;
		n = n / 10;
	}
	
	DMSum(digit + num);
}
int factorial(int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return 1;
	}
	if (n % 2 != 0)
	{
		return factorial(n - 1) * n;
	}
	else
	{
	  return factorial(n - 1)*n*(-1);
	}
}
int main()
{
	cout << factorial(3);
}
