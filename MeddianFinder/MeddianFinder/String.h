
#ifndef STRING_H
#define STRING_H
#include <iostream>
using namespace std;
class String
{
	char* data;
	int size;
	bool isValidIndex(int index) const;
	int getNumberLength(long long int num) const;
	int getLengthOfArray(const char* arr);
	int getRightWhiteSpaces();
	int getLeftWhiteSpaces();
public:
	String();
	String(int);
	String(const char c);
	String(int count, ...);
	String(const char* arr);
	void input();
	String(const String& r);
	~String();
	String& operator=(const String& other);
	
	
	
	void shrink();
	char& operator [](const int index);
	const char& operator [](const int index) const;
	bool operator !() const;

	bool isEmpty() const;

	int getLength() const;
	int getSize() const;
	void display() const;
	int find(String substr, int startIndex) const;
	void insert(int index, String subStr);
	void remove(int startIndex, int count = 1);
	int replace(String old, String newSub);
	void trimLeft();
	void trimRight();
	void trim();
	void makeUpper();
	void makeLower();
	void reverse();
	void reSize(int newSize);
	int operator ==(String& s2) const;
	String operator +(const String& s2) const;
	void operator +=(const String& s2);
	String& operator =(const long long int num);
	explicit operator long long int()const;
	explicit operator bool() const;
	String operator()(const String& delim);
	int compare(String& s2) const;
	String left(int count);
	String right(const int count);
	long long int convertToInteger() const;
	float convertToFloat() const;

};
istream& operator >>(istream& os, String& str);
ostream& operator <<(ostream& os, const String& str);

#endif
