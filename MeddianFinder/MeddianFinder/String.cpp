#include<stdarg.h>
#include "String.h"
bool String::isValidIndex(int index) const
{
	return (index >= 0 && index < size - 1);
}
int String::getNumberLength(long long int num) const
{
	if (num == 0)
	{
		return 1;
	}

	int count = 0;
	long long int n = num;
	if (n < 0)
	{
		count++;
		n = (-1) * n;
	}

	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return count;
}
int String::getLengthOfArray(const char* arr)
{
	int i = 0;

	while (arr[i] != '\0')
	{
		i++;
	}
	return i;
}
int String::getLeftWhiteSpaces()
{
	int spaces = 0;
	int len = getLength();
	for (int i = 0; i < len; i++)
	{
		if (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
		{
			spaces++;
		}
		else
		{
			break;
		}
	}
	return spaces;
}

int String::getRightWhiteSpaces()
{
	int spaces = 0;
	int i = getLength()-1;
	for ( ; i >= 0; i--)
	{
		if (data[i] == ' ' || data[i] == '\t' || data[i] == '\n')
		{
			spaces++;
		}
		else
		{
			break;
		}
	}
	return spaces;

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
	va_start(list, count);
	data = new char[count + 1];
	for (int i = 0; i < count; i++)
	{
		data[i] = va_arg(list, int);
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
	if (!arr)
		return;
	int len = getLengthOfArray(arr);
	data = new char[len + 1];
	size = len + 1;
	int i;
	for (i = 0; i < len ; i++)
	{
		data[i] = arr[i];
	}
	data[i] = '\0';
}
void String::input()
{
	remove(0, getLength());
	cout << "Enter : ";
	char ch;
	int i = 0;
	
	while ((ch = cin.get()) != '\n')
	{
		insert(i++, String(ch));
	}
}
String::String(const String& r) :String()
{
	if (r.size == 0)  return;

	size = r.size;
	data = new char[size];
	
	for (int i = 0; i < size - 1; i++)
	{
		data[i] = r.data[i];
	}
	data[size - 1] = '\0';
}
String::~String()
{
	if (data)
	{
		delete[]data;
		data = nullptr;
	}
	size = 0;
}
const char& String::operator [](const int index) const
{
	if (!isValidIndex(index))
	{
		cout << "Invalid index access\n";
		exit(0);
	}

	return data[index];
}
bool String::operator !() const
{
	return !isEmpty();
}
bool String::isEmpty() const
{
	return ((data == nullptr) || (data[0] == '\0'));
}
int String::getSize() const
{
	return size;
}
int String::getLength() const
{
	if (!data)  return 0;
	int length = 0;
	
	while ((data[length] != '\0') && (length < size - 1))
	{
		length++;
	}
	return length;
}
void String::display() const
{
	if (!data)
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
	
	char* temp = new char[newSize];
	
	if (data)
	{
		int i = 0;
		while (data[i] != '\0' && i < newSize - 1)
		{
			temp[i] = data[i];
			i++;
		}
		temp[i] = '\0';
	}
	else
	{
		temp[0] = '\0';
	}

	delete[] data;
	data = temp;
	size = newSize;
	
}
void String::insert(int index, String subStr)
{
	if (!subStr.data) return;

	int origLen = getLength();
	int subLen = subStr.getLength();
	int newSize = origLen + subLen + 1;

	char* temp = new char[newSize];

	int i = 0;
	for ( ; i < index && i< origLen; i++)
	{
		temp[i] = data[i];
	}
	int j = 0;
	for ( ; j < subLen; j++, i++)
	{
		temp[i] = subStr.data[j];
	}
	for (j = index; i < origLen; j++, i++)
	{
		temp[i] = data[j];
	}
	temp[i] = '\0';

	delete[] data;
	data = temp;
	size = newSize;
	
}
int String::find(String substr, int startIndex=0) const
{
	int subLen = substr.getLength();
	int occurrences = 0;
	int strLen = getLength();

	for (int i = startIndex; i < strLen; i++)
	{
		if (substr.data[0] == data[i])
		{
			int j = 0;
			int tempPos= i;
			int matchCount = 0;
			while ((j < subLen) && (substr.data[j] == data[tempPos]))
			{
				tempPos++;
				j++;
				matchCount++;
			}
			if (matchCount == subLen)
			{
				occurrences++;
			}
		}
	}
	return occurrences; 

}
int String::replace(String old, String newSub)
{
	int oldLen = old.getLength();
	int occurrences = 0;
	int matchCount= 0;
	for (int i = 0; i < size - 1; i++)
	{
		if (old.data[0] == data[i])
		{
			int j= 0;
			int tempPos = i;
			while ((j < oldLen) && (old.data[j] == data[tempPos]))
			{
				tempPos++;
				j++;
				matchCount++;
			}
			if (matchCount == oldLen)
			{
				tempPos = tempPos - oldLen;
				remove(tempPos, oldLen);
				insert(tempPos, newSub);
				occurrences++;
			}
			matchCount = 0;
		}
	}
	return occurrences;
}
void String::remove(int startIndex, int count)
{
	int strLen = getLength();
	if (startIndex < 0 || startIndex >= strLen || count < 0 || startIndex + count > strLen)
	{
		return;
	}
	int newSize = size - count;
	char* temp = new char[newSize];
	int i;
	for (i = 0; i < startIndex; i++)
	{
		temp[i] = data[i];
	}
	for (i = startIndex; i < newSize - 1; i++)
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
	for (int i = 0; data[i] != '\0'; i++)
	{
		if ((data[i] >= 'a') && (data[i] <= 'z'))
		{
			data[i] = data[i] - ('a'-'A');
		}
	}
}
void String::makeLower()
{
	for (int i = 0; data[i] != '\0'; i++)
	{
		if ((data[i] >= 'A') && (data[i] <= 'Z'))
		{
			data[i] = data[i] + ('a' - 'A');
		}
	}
	
}
void String::reverse()
{
	int len = getLength();
	for (int start = 0; start < len / 2; start++)
	{
		char temp = data[start];
		data[start] = data[len - start - 1];
		data[len - start - 1] = temp;
	}
}
void String::trimLeft()
{
	int leftSpaces = getLeftWhiteSpaces();
	int newSize = size - leftSpaces;
	char* temp = new char[newSize];
	
	
	for (int i = 0; i < newSize - 1; i++)
	{
		temp[i] = data[i + leftSpaces];
	}
	temp[newSize - 1] = '\0';
	delete[] data;
	data = temp;
	size = newSize;
}
void String::trimRight()
{
	int rightSpaces = getRightWhiteSpaces();
	int newSize = size - rightSpaces;
	char* temp = new char[newSize];
	
	for (int i = 0; i < (newSize - 1); i++)
	{
		temp[i] = data[i];
	}
	temp[newSize - 1] = '\0';
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
	int len = getLength(); 
	char* temp = new char[len + 1];
	int i;
	for ( i = 0; i < len; i++) 
	{ 
		temp[i] = data[i];
	}
	temp[i] = '\0'; 
	delete[] data; 
	data = temp; 
	size = len + 1;
}
String String::left(int count)
{
	String result{ *this };
	int len = getLength();
	if ((!(*this)) || (count > len))
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return result;
	}
	if (count == 0)
	{
		result.~String();
		return result;
	}
	if ((count > 0))
	{
		result.data[count] = '\0';
		result.size = count;
		for (int i = 0; i < len - count; i++)
		{
			data[i] = data[count + i];
		}
		data[getLength() - count] = '\0';
		return result;
	}
	cout << "Index out of range";
	exit(0);
}
String String::right(int count)
{
	String result{ *this };
	int len = getLength();
	if ((!(*this)) || (count > len))
	{
		delete[] data;
		data = nullptr;
		size = 0;
		return result;
	}
	if (count == 0)
	{
		result.~String();
		return result;
	}
	else if (count > 0)
	{
		result.size = count + 1;
		result.data = new char[result.size];
		for (int i = len - count, j = 0; i < len; i++, j++)
		{
			result.data[j] = data[i];
		}
		result.data[result.size - 1] = '\0';
		data[count + 1] = '\0';
		return result;
	}
	cout << "Index out of range";
	exit(0);
}
String& String::operator =(const long long int num)
{
	int len = getNumberLength(num);
	long long int tempnum = num;
	char* temp = new char[len];
	int index = 0;
	if (num < 0)
	{
		while (tempnum != '\0')
		{
			temp[index++] = '0' + ((-1) * (tempnum % 10));
			tempnum /= 10;
		}
		temp[index++] = '-';
	}
	else
	{
		while (tempnum != '\0')
		{
			temp[index++] = '0' +  (tempnum % 10);
			tempnum /= 10;
		}
		
	}
	temp[index] = '\0';
	delete[] data;
	data = temp;
	size = len;
	reverse();
	return *this;
}
long long int String::convertToInteger() const
{
	
		if (isEmpty()) return 0;

		int len = getLength();
		int i = 0; ;
		long long int n = 0;
		bool isNegative = false;
		if (data[i] == '-')
		{
			isNegative = true;
			i++;
		}
		for (; i < len; i++)
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				n = (data[i] - 48) + n * 10;
			}
			else
			{
				cout << "Invalid character in string";
				exit(0);
			}
		}
		if (isNegative)
		{
			n = n * -1;
		}
		return n;
	

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
	if (isEmpty()) return 0.0;
	int i = 0;
	float n = 0.0;
	float fracPart = 0.0;
	bool isNegative = false;
	if (data[i] == '-')
	{
		isNegative = true;
		i++;
	}
	while (data[i] != '\0' && data[i] != '.')
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			n = (data[i] - '0') + n * 10;
		}
		else
		{
			cout << "Invalid character in string";
			exit(0);
		}
		i++;
	}
	if (data[i] == '.')
	{
		i++;
		float divisor = 10.0;
		while (data[i] != '\0')
		{
			if (data[i] >= '0' && data[i] <= '9')
			{
				fracPart += (data[i] - '0') / divisor;
				divisor *= 10;
			}
			else
			{
				cout << "Invalid character in string";
				exit(0);
			}
			i++;
		}
	}
	n += fracPart;
	if (isNegative)
	{
		n = n * -1;
	}

	return n;
}


String String::operator +(const String& s2) const
{
	int newLen = size + s2.size - 1;
	String n;
	n.data = new char[newLen];
	n.size = newLen;
	int len = size - 1;
	int i;
	for (i = 0; i < len; i++)
	{
		n.data[i] = data[i];
	}
	int j;
	int k = 0;
	for (j = i; j < newLen - 1; j++, k++)
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
	delete[] data;
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
	if (isEmpty()) return 0;

	int len = getLength();
	int i = 0; ;
	long long int n = 0;
	bool isNegative = false;
	if (data[i] == '-')
	{
		isNegative = true;
		i++;
	}
	for (; i < len; i++)
	{
		if (data[i] >= '0' && data[i] <= '9')
		{
			n = (data[i] - 48) + n * 10;
		}
		else
		{
			cout << "Invalid character in string";
			exit(0);
		}
	}
	if (isNegative)
	{
		n = n * -1;
	}
	return n;

}
String::operator bool() const
{
	return !isEmpty();
}
istream& operator >>(istream& os, String& str)
{
	
	str.remove(0, str.getLength()); 

	string temp;
	os >> temp;                     

	
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
	String result;
	if (delim.isEmpty())
	{
		result = *this;
		remove(0, getLength());
		return result;
	}
	int index = 0, stop = 0, removeCount = 0;
	while ((data[index] != '\0') && (stop == 0))
	{
		int dIndex = 0;
		int found = 0;
		while ((delim.data[dIndex] != '\0') && (found == 0))
		{
			if (data[index] == delim.data[dIndex])
			{
				found = 1;
				break;
			}
			dIndex++;
		}
		if (found == 0)
		{
			char ch = data[index];
			String temp{ ch };
			result += temp;
		}
		else
		{
			stop = 1;
			
			removeCount = index + 1;
		}
		index++;
	}
	if (data[index] == '\0')
	{
		removeCount = result.getLength();
	}
	remove(0, removeCount);
	return result;
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
	if (n > 0)
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





