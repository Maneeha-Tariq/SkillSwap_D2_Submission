#include<stdarg.h>
#include "String.h"
bool String::isValidIndex(int index) const
{
	return (index >= 0 && index < size -1 );
}
int String::getNumberLength(long long int num) const
{
	int count = 0;
	long long int n = num;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	
	if (num < 0)
	{
		count = count + 3;
	}
	else
	{
		count = count + 2;
	}
	return count;
}


int String::getLengthOfArray(const char* arr)
{
	int counter = 0;
	int j = 0;
	while (arr[j] != '\0')
	{
		counter++;
		j++;
	}
	return counter;
}
int String::getRightWhiteSpaces()
{
	int whiteSpaces = 0;
	int len = getLength();
	int index = len - 1;
	while (((data[index] == '\n') || (data[index] == '\t') || (data[index] == ' ')))
	{
		whiteSpaces++;
		index--;
	}
	return whiteSpaces;
}
int String::getLeftWhiteSpaces()
{
	int whiteSpaces = 0;
	int index = 0;
	while (((data[index] == '\n') || (data[index] == '\t') || (data[index] == ' ')))
	{
		whiteSpaces++;
		index++;
	}
	return whiteSpaces;
}
String::String()
{
	data = nullptr;
	size = 0;
}
String::String(int count, ...) :String()
{
	if (count <= 0)
		return;
	va_list list;
	data = new char[count + 1];
	va_start(list, count);
	for (int i = 0; i < count; i++)
	{
		data[i] = va_arg(list, char);
	}
	data[count] = '\0';
	va_end(list);
	size = count + 1;
}
String::String(const char c)
{
	data = new char[2];
	data[0] = c;
	data[1] = '\0';
	size = 2;
}
String::String(const char* arr) :String()
{
	if (arr == nullptr)
		return;
	int len = getLengthOfArray(arr);
	data = new char[len + 1];
	size = len + 1;
	int i;
	for (i = 0; i < size - 1; i++)
	{
		data[i] = arr[i];
	}
	data[i] = '\0';
}
void String::input()
{
	int i = 0;
	remove(0, getLength());
	cout << "Enter : ";
	char ch;
	ch = cin.get();
	while (ch != '\n')
	{
		String c{ ch };
		insert(i, c);
		i++;
		ch = cin.get();
	}
}
String::String(const String& r) :String()
{
	if (r.size == 0)
	{
		return;
	}
	size = r.size;
	data = new char[size];
	int i;
	for (i = 0; i < size - 1; i++)
	{
		data[i] = r.data[i];
	}
	data[i] = '\0';
}
String::~String()
{
	if (data != nullptr)
	{
		delete[]data;
		data = nullptr;
	}
	size = 0;
}
const char& String::operator [](const int index) const
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		cout << "Invalid access of index";
		exit(0);
	}
}
bool String::operator !() const
{
	return !isEmpty();
}
bool String::isEmpty() const
{
	if ((data == nullptr) || (data[0] == '\0'))
	{
		return true;
	}
	else
	{
		return false;
	}
}
int String::getSize() const
{
	return size;
}
int String::getLength() const
{
	if (data == nullptr)
		return 0;
	int counter = 0;
	int i = 0;
	while ((data[i] != '\0') && (i < size - 1))
	{
		counter++;
		i++;
	}
	return counter;
}
void String::display() const
{
	if (data == nullptr)
		return;
	cout << data;
}
void String::reSize(int newSize)
{
	if (newSize <= 0)
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return;
	}
	else
	{
		char* temp = new char[newSize];
		int i = 0;
		if (data != nullptr)
		{
			while (data[i] != '\0' && i < newSize - 1)
			{
				temp[i] = data[i];
				i++;
			}
			temp[i] = '\0';
		}

		delete[] data;
		data = temp;
		size = newSize;
	}
}
void String::insert(int index, String subStr)
{
	if (subStr.data == nullptr)
	{
		return;
	}
	else
	{
		int newSize = getLength() + subStr.getLength() + 1;
		char* temp = new char[newSize];
		int i;
		for (i = 0; i < index; i++)
		{
			temp[i] = data[i];
		}
		int j;
		for (j = 0; j < subStr.getLength(); j++, i++)
		{
			temp[i] = subStr.data[j];
		}
		for (j = index; i < newSize - 1; j++, i++)
		{
			temp[i] = data[j];
		}
		temp[i] = '\0';

		delete[] data;
		data = temp;
		size = newSize;
	}
}
int String::find(String substr, int count) const
{
	int len = substr.getLength();
	int occurrence = 0;
	int counter = 0;
	for (int index1 = count; index1 < size - 1; index1++)
	{
		if (substr.data[0] == data[index1])
		{
			int index2 = 0;
			int tempIndex = index1;
			while ((index2 < len) && (substr.data[index2] == data[tempIndex]))
			{
				tempIndex++;
				index2++;
				counter++;
			}
			if (counter == len)
			{
				occurrence++;
			}
			counter = 0;
		}
	}
	return occurrence;
}
int String::replace(String old, String newSubStr)
{
	int len = old.getLength();
	int occurrence = 0;
	int counter = 0;
	for (int index1 = 0; index1 < size - 1; index1++)
	{
		if (old.data[0] == data[index1])
		{
			int index2 = 0;
			int tempIndex = index1;
			while ((index2 < len) && (old.data[index2] == data[tempIndex]))
			{
				tempIndex++;
				index2++;
				counter++;
			}
			if (counter == len)
			{
				tempIndex = tempIndex - len;
				remove(tempIndex, len);
				insert(tempIndex, newSubStr);
				occurrence++;
			}
			counter = 0;
		}
	}
	return occurrence;
}
void String::remove(int index, int count)
{
	if (index < 0 || index >= getLength() || count < 0 || index + count > getLength())
	{
		return;
	}
	int newSize = size - count;
	char* temp = new char[newSize];
	int i;
	for (i = 0; i < index; i++)
	{
		temp[i] = data[i];
	}
	for (i = index; i < newSize - 1; i++)
	{
		temp[i] = data[i + count];
	}
	temp[i] = '\0';
	delete[] data;
	data = temp;
	size = newSize;
}
void String::makeUpper()
{
	int index = 0;
	while (data[index] != '\0')
	{
		if ((data[index] >= 'a') && (data[index] <= 'z'))
		{
			data[index] = data[index] - 32;
		}
		index++;
	}
}
void String::makeLower()
{
	int index = 0;
	while (data[index] != '\0')
	{
		if ((data[index] >= 'A') && (data[index] <= 'Z'))
		{
			data[index] = data[index] + 32;
		}
		index++;
	}
}
void String::reverse()
{
	int i = getLength();
	for (int index = 0; index < i / 2; index++)
	{
		char temp = data[index];
		data[index] = data[i - index - 1];
		data[i - index - 1] = temp;
	}
}
void String::trimLeft()
{
	int noOfWhiteSpaces = getLeftWhiteSpaces();
	int newSize = size - noOfWhiteSpaces;
	char* temp = new char[newSize];
	int index;
	int inc = noOfWhiteSpaces;
	for (index = 0; index < newSize - 1; index++)
	{
		temp[index] = data[index + inc];
	}
	temp[index] = '\0';
	delete[] data;
	data = temp;
	size = newSize;
}
void String::trimRight()
{
	int noOfWhiteSpaces = getRightWhiteSpaces();
	int newSize = size - noOfWhiteSpaces;
	char* temp = new char[newSize];
	int index;
	for (index = 0; index < (newSize - 1); index++)
	{
		temp[index] = data[index];
	}
	temp[index] = '\0';
	delete[] data;
	data = temp;
	size = newSize;
}
void String::trim()
{
	trimRight();
	trimLeft();
}
void String::shrink()
{
	int newSize = getLength() + 1;
	char* temp = new char[newSize];
	int index;
	for (index = 0; index < newSize - 1; index++)
	{
		temp[index] = data[index];
	}
	temp[index] = '\0';
	delete[] data;
	data = temp;
	size = newSize;
}
String String::left(int count)
{
	String b{ *this };
	if ((!(*this)) || (count > getLength()))
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return b;
	}
	if (count == 0)
	{
		b.~String();
		return b;
	}
	if ((count > 0))
	{
		b.data[count] = '\0';
		b.size = count;
		for (int i = 0; i < getLength() - count; i++)
		{
			data[i] = data[count + i];
		}
		data[getLength() - count] = '\0';
		return b;
	}
	cout << "Index out of range";
	exit(0);
}
String String::right(int count)
{
	String b{ *this };
	if ((!(*this)) || (count > getLength()))
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return b;
	}
	if (count == 0)
	{
		b.~String();
		return b;
	}
	else if (count > 0)
	{
		b.size = count + 1;
		b.data = new char[b.size];
		for (int i = getLength() - count, j = 0; i < getLength(); i++, j++)
		{
			b.data[j] = data[i];
		}
		b.data[b.size - 1] = '\0';
		data[count + 1] = '\0';
		return b;
	}
	cout << "Index out of range";
	exit(0);
}
String& String::operator =(const long long int num)
{
	int len = getNumberLength(num);
	long long int n = num;
	char* temp = new char[len];
	int i;
	if (num < 0)
	{
		for (i = 0; i < len - 2; i++)
		{
			temp[i] = ((n % 10) * -1) + 48;
			n = n / 10;
		}
		temp[i] = '-';
		i = i + 1;
	}
	else
	{
		for (i = 0; i < len - 1; i++)
		{
			temp[i] = (n % 10) + 48;
			n = n / 10;
		}
	}
	temp[i] = '\0';
	delete[] data;
	data = temp;
	size = len;
	reverse();
	return *this;
}
long long int String::convertToInteger() const
{
	long long int n = 0;
	int flag = 1;
	int index = 0, sign = 1;
	if (data[0] == '-')
	{
		index = 1;
		sign = -1;
	}
	for (; index < (size - 1) && (flag == 1); index++)
	{
		if (data[index] >= '0' && data[index] <= '9')
		{
			n = (data[index] - 48) + n * 10;
		}
		else
		{
			flag = 0;
		}
	}
	return n * sign;
}
void String::operator +=(const String& s2)
{
	if (s2.data == nullptr)
		return;
	int n = getLength();
	insert(n, s2);
}
float String::convertToFloat() const
{
	float n = 0.0;
	int i = 0, sign = 1;
	if (data[0] == '-')
	{
		i = 1;
		sign = -1;
	}
	int flag = 0;
	float div = 10.0;
	int check = 1;
	for (; i < (size - 1) && (check == 1); i++)
	{
		if ((data[i] >= '0' && data[i] <= '9') || (data[i] == '.'))
		{
			if (data[i] == '.')
			{
				flag = 1;
			}
			else if (flag == 1)
			{
				n = ((data[i] - 48) / div) + n;
				div = div * 10;
			}
			else
			{
				n = (data[i] - 48) + n * 10;
			}
		}
		else
		{
			check = 0;
		}
	}
	return n * sign;
}
String String::operator +(const String& s2) const
{
	int newSize = size + s2.size - 1;
	String n;
	n.data = new char[newSize];
	n.size = newSize;
	int i;
	for (i = 0; i < size - 1; i++)
	{
		n.data[i] = data[i];
	}
	int j;
	int k = 0;
	for (j = i; j < newSize - 1; j++, k++)
	{
		n.data[j] = s2.data[k];
	}
	n.data[j] = '\0';
	return n;
}
String& String::operator=(const String& r)
{
	if (r.isEmpty())
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return *this;
	}
	if (this == &r)
		return *this;
	this->~String();
	size = r.size;
	data = new char[size];
	int i;
	for (i = 0; i < size; i++)
	{
		data[i] = r.data[i];
	}
	return *this;
}
int String::operator ==(String& s2) const
{
	if (isEmpty() && s2.isEmpty())
	{
		return 0;
	}
	else if (isEmpty() && !s2.isEmpty())
	{
		return -1;
	}
	else if (!isEmpty() && s2.isEmpty())
	{
		return 1;
	}
	int i = 0;
	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		if (data[i] < s2.data[i])
		{
			return -1;
		}
		else if (data[i] > s2.data[i])
		{
			return 1;
		}

		i++;
	}
	if (data[i] == s2.data[i])
	{
		return 0;
	}
	else if (data[i] < s2.data[i])
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
char& String::operator [](const int index)
{
	if (isValidIndex(index))
	{
		return data[index];
	}
	else
	{
		cout << "Invalid access of index";
		exit(0);
	}

}
String::operator long long int()const
{
	long long int n = 0;
	int flag = 1;
	int index = 0, sign = 1;
	if (data[0] == '-')
	{
		index = 1;
		sign = -1;
	}
	for (; index < (size - 1) && (flag == 1); index++)
	{
		if (data[index] >= '0' && data[index] <= '9')
		{
			n = (data[index] - 48) + n * 10;
		}
		else
		{
			flag = 0;
		}
	}
	return n * sign;
}
String::operator bool() const
{
	return !isEmpty();
}
istream& operator >>(istream& os, String& str)
{
	/*str.input();*/
	str.remove(0, str.getLength());  // purana data hatao

	string temp;
	os >> temp;                      // file ya console se read karo

	// har character insert karo
	for (int i = 0; i < temp.length(); i++)
	{
		String ch(temp[i]);
		str.insert(i, ch);
	}

	return os;
}
int String::compare(String& s2) const
{
	if (isEmpty() && s2.isEmpty())
	{
		return 0;
	}
	else if (isEmpty() && !s2.isEmpty())
	{
		return -1;
	}
	else if (!isEmpty() && s2.isEmpty())
	{
		return 1;
	}
	int i = 0;
	while (data[i] != '\0' && s2.data[i] != '\0')
	{
		if (data[i] < s2.data[i])
		{
			return -1;
		}
		else if (data[i] > s2.data[i])
		{
			return 1;
		}

		i++;
	}
	if (data[i] == s2.data[i])
	{
		return 0;
	}
	else if (data[i] < s2.data[i])
	{
		return -1;
	}
	else
	{
		return 1;
	}
}
String String::operator()(const String& delim)
{
	String ret;
	if (delim.isEmpty())
	{
		ret = *this;
		remove(0, getLength());
		return ret;
	}
	int i = 0, flag1 = 0, count = 0;
	while ((data[i] != '\0') && (flag1 == 0))
	{
		int j = 0;
		int flag2 = 0;
		while ((delim.data[j] != '\0') && (flag2 == 0))
		{
			if (data[i] == delim.data[j])
			{
				flag2 = 1;
			}
			j++;
		}
		if (flag2 == 0)
		{
			char c = data[i];
			String t{ c };
			ret += t;
		}
		else
		{
			flag1 = 1;
			char c = '\0';
			String t{ c };
			ret += t;
			count = ret.getLength() + 1;
		}
		i++;
	}
	if (data[i] == '\0')
	{
		count = ret.getLength();
	}
	remove(0, count);
	return ret;
}
String::String(int n)
{
	int count = 0;
	int num = n;
	while (num != 0)
	{
		count++;
		num = num / 10;
	}
	int len = 0;
	if(n>0)
	{ 
		len = len + count;
	}
	else
	{
		len = len + count + 1;
	}
	char* temp = new char[len + 2];
	if (n == 0)
	{
		data = new char[2];
		data[0] = '0';
		data[1] = '\0';
		size = 2;
		return;
	}

	int i = 0;
	if (n < 0)
	{
		n = (-1) * n;
		temp[i++] = '-';
	}

	while (n != 0)
	{
		int digit = n % 10;
		n = n / 10;
		temp[i++] = digit + '0';
	}
	temp[i] = '\0';

	int rev_start = (temp[0] == '-') ? 1 : 0;
	int rev_end = i - 1;
	while (rev_start < rev_end)
	{
		char t = temp[rev_start];
		temp[rev_start] = temp[rev_end];
		temp[rev_end] = t;
		rev_start++;
		rev_end--;
	}

	data = new char[i + 1];
	for (int j = 0; j < i; j++)
	{
		data[j] = temp[j];
	}

	data[i] = '\0';
	size = i + 1;


	delete[] temp;

}
ostream& operator <<(ostream& os, const String& str)
{
	str.display();
	return os;
}

