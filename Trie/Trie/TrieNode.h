#ifndef TRIENODE_H
#define TRIENODE_H
#include <iostream>
using namespace std;
struct TrieNode
{
	bool endOfWord;
	TrieNode* children[26];
	TrieNode()
	{
		endOfWord = false;
	}
};
#endif