
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
		out << r[i] ;
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
void rotateNaiveSquare(Array<Array<int>>& mat)
{
	int rows = mat.getSize();
	int columns = mat[0].getSize();

	int j = rows - 1, start, end;
	// reverse column
	for (int i = 0; i < rows; i++)
	{
		start = 0;
		end = j;
		while (start < end)
		{
			int temp = mat[start][i];
			mat[start][i] = mat[end][i];
			mat[end][i] = temp;
			start++;
			end--;
		}
	}
	//transpose 
	for (int i = 0; i < rows; i++)
	{
		for (int j = i; j <columns ; j++)
		{
			int temp = mat[i][j];
			mat[i][j] = mat[j][i];
			mat[j][i] = temp;
		}
	}
	
}
void rotateNaive(Array<Array<int>>& mat)
{
	int rows = mat.getSize();
	int columns = mat[0].getSize();

	int rotRows = columns;
	int rotColumns = rows;

	Array<Array<int>> rotated(rotRows);
	for (int i = 0; i < rotRows; i++)
	{
		rotated[i].reSize(rotColumns);
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			rotated[j][rows - i - 1] = mat[i][j];
		}
	}
	mat = rotated;
}
bool readPGM(const string& filename, Array<Array<int>>& matrix, int& width, int& height, int& maxVal)
{
	ifstream file(&filename[0]);
	if (!file.is_open())
	{
		cerr << "Error: " << "Cannot open file" << filename << endl;
		return false;
	}
	string format;
	format.resize(3);
	file.getline(&format[0], 3);
	if ((format == "P2")!=0 )
	{
		cerr << "Error: " << "Cannot open file" << filename << endl;
		return false;
	}
	char cmnt = file.peek();
	if (cmnt == '#')
	{
		string comment;
		file >> comment;
	}
	file >> width >> height >> maxVal;
	matrix.reSize(height);
	for (int i = 0; i < matrix.getSize(); i++)
	{
		matrix[i].reSize(width);
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file >> matrix[i][j];
		}
	}
	file.close();
	
	return true;
}
bool writePGM(const string& filename, Array<Array<int>>& matrix, int& width, int& height, int& maxVal)
{
	ofstream file(&filename[0]);
	if (!file.is_open())
	{
		cerr << "Error: " << "Cannot open file" << filename << endl;
		return false;
	}
	file << "P2" << "\n";
	file << width << " "<< height << "\n" << maxVal<<"\n";

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			file << matrix[i][j]<< " ";
		}
		file << "\n ";
	}
	file.close();
	return true;
}

void rotateP2PGM(string inputFileName, string outputFileName)
{
	Array<Array<int>> matrix;
	int width = 0, height = 0, maxVal = 0;
	readPGM(inputFileName, matrix, width,height ,maxVal );
	rotateNaive(matrix);
	int newW = height;
	int newH = width;
	writePGM(outputFileName, matrix, newW, newH, maxVal);
}


int main()
{
	ofstream ofs("output.pgm");
	rotateP2PGM("a.pgm", "outt.pgm");
	
}
















//1d 
/*Array<int> a = { 10,56,9 };*/

	/*for (int i = 0; i < a.getSize(); i++)
	{
		fout << a[i] << " ";
	}
	fout.close();

	ifstream ifs("filename.txt");
	int count = 0, x;
	while (ifs >> x) count++;
	ifs.clear();
	ifs.seekg(0);
	Array<int> t(count);
	for (int i = 0; i < count; i++)
	{
		ifs >> t[i];
	}
	ifs.close();
	cout << t;*/
// 1D array
	/*Array<int> a =  {1,2,3};
	Array<int> t;
	ofstream fout("filename.txt");
	fout << a.getSize() << "\n";
	for (int i = 0; i < a.getSize(); i++)
	{
		fout << a[i] << " ";
	}
	fout.close();

	ifstream fin("filename.txt");
	int s;
	fin >> s;
	t.reSize(s);
	for (int i = 0,j=0; i < s; i++)
	{
		fin >> t[i];
	}
	fin.close();

	cout<< t;*/
	// 2D array
	/*Array<Array<int>> b = { {1,2,3},{4,5,6},{7,8,9} };
	Array<Array<int>> s;
	ofstream fout("name.txt");
	fout << b.getSize() << "\n";
	for (int i = 0; i < b.getSize(); i++)
	{
		fout << b[i].getSize() << " ";
		for (int j = 0; j < b[i].getSize(); j++)
		{
			fout << b[i][j] << " ";
		}
		fout << "\n";
	}
	fout.close();

	ifstream fin("name.txt");
	int rows;
	fin >> rows;
	b.reSize(rows);
	for (int i = 0, j = 0; i < rows; i++)
	{
		int cols;
		fin >> cols;
		b[i].reSize(cols);
		for (int j = 0; j < cols; j++)
		{
			fin >> b[i][j];
		}
	}
	fin.close();
	cout << b;*/

	//short 2d array
	/*Array<Array<int>> a = { {1,2,3},{4,5,6},{7,8,9} };


	ofstream fout("filename.txt");
	for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < a[i].getSize(); j++)
		{
			fout << a[i][j] << " ";
		}
	}
	fout.close();


	ifstream fin("filename.txt");
	int count = 0, x;
	while (fin >> x) count++;
	fin.clear();
	fin.seekg(0);

	Array<int> t(count);
	for (int i = 0; i < count; i++)
	{
		fin >> t[i];
	}
	fin.close();

	cout << "Loaded array: " << t << endl;*/


	//3D array
	/*Array<Array<Array<int>>> a = {
	   { {1,2,3}, {4,5,6} },
	   { {7,8,9}, {10,11,12} }
	};

	ofstream fout("file.txt");
	for (int i = 0; i < a.getSize(); i++)
	{
		for (int j = 0; j < a[i].getSize(); j++)
		{
			for (int k = 0; k < a[i][j].getSize(); k++)
			{
				fout << a[i][j][k] << " ";
			}
		}
	}
	fout.close();


	ifstream fin("file.txt");
	int count = 0, x;
	while (fin >> x) count++;
	fin.clear();
	fin.seekg(0);

	Array<int> t(count);
	for (int i = 0; i < count; i++)
	{
		fin >> t[i];
	}
	fin.close();

	cout << "Loaded array: " << t << endl; */



//jagged array
//int rows;
//cout << "Enter no of rows: ";
//cin >> rows;
//
//Array<Array<int>> a(rows);
//for (int i = 0; i < rows; i++)
//{
//	int cols;
//	cout << "Enter no of elements in row " << i + 1 << ": ";
//	cin >> cols;
//	a[i].reSize(cols);
//	for (int j = 0; j < cols; j++)
//	{
//		cin >> a[i][j];
//	}
//}
//cout << "Output\n";
//for (int i = 0; i < a.getSize(); i++)
//{
//	for (int j = 0; j < a[i].getSize(); j++)
//	{
//		cout << a[i][j] << " ";
//	}
//	cout << endl;
//}
