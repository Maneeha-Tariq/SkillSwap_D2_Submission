#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.h"
#include "String.h"
#include<iostream>
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

class Trie
{
	TrieNode* root;

	void collectWords(TrieNode* node, String currentWord, Array<String>& result)
	{
		if (node->endOfWord == true)
		{
			int n = result.getSize();
			result.reSize(n + 1);
			result[n] = currentWord;
		}
		for (int j = 0; j < 26; j++)
		{
			if (node->children[j])
			{
				char c = j + 'a';
				collectWords(node->children[j], currentWord + c, result);
			}
		}
	}

public:
	Trie() 
	{
		root = new TrieNode();
	}
	void insert(String word)
	{
		TrieNode* p = root;
		int len = word.getLength();
		for (int i = 0; i < len; i++)
		{
			int indx = word[i] - 'a';

			if (indx < 0 || indx>25)
			{
				continue;
			}
			if (!p->children[indx])
			{
				p->children[indx] = new TrieNode();
			}
			p = p->children[indx];
		}

		p->endOfWord = true;
	}
	bool search(String word)
	{
		bool find = false;
		TrieNode* p = root;
		int len = word.getLength();
		for (int i = 0; i < len; i++)
		{
			int indx = word[i] - 'a';
			if (indx < 0 || indx>25)
			{
				return false;
			}
			if (p->children[indx])
			{
				find = true;
				p = p->children[indx];
			}
			else
			{
				find = false;
				break;
			}
		}
		if (p->endOfWord == true && find == true)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	Array<String> autoComplete(String prefix)
	{
		Array<String> str;
		TrieNode* p = root;
		int i = 0;
		while (prefix[i] != '\0')
		{
			int indx = prefix[i] - 'a';
			if (indx < 0 || indx > 25 || !p->children[indx])
			{
				return Array<String>();
			}
			p = p->children[indx];
			i++;
		}
		collectWords(p, prefix, str);
		return str;

	}

};
#endif