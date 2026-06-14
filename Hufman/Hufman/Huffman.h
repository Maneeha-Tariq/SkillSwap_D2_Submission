#ifndef HUFFMAN_H
#define HUFFMAN_H
#include "HuffmanNode.h"
#include "String.h"
#include "MinHeap.h"
#include<iostream>
using namespace std;
class Huffman
{
	HuffmanNode* root;
	int freq[256];
	String message;
	MinHeap<HuffmanNode*> heap;

	void setFreq(String& str)
	{

		int len = str.getLength();
		for (int i = 0; i < len; i++)
		{
			int ascii = (int)str[i];
			freq[ascii]++;
		}
		for (int i = 0; i < 256; i++)
		{
			if (freq[i] > 0)
			{
				HuffmanNode* n = new HuffmanNode();
				n->symbol = (char)i;
				n->frequency = freq[i];
				n->probability = ((double)freq[i] / len) * 100;
				n->left = nullptr;
				n->right = nullptr;
				heap.insert(n);

			}
		}
	}
	void assignCodes(HuffmanNode* root, String code = "")
	{
		if (!root)
		{
			return;
		}
		if (root->left == NULL && root->right == NULL)
		{
			root->code = code;
			return;
		}
		assignCodes(root->left, code + "0");
		assignCodes(root->right, code + "1");
	}

public:

	Huffman(String& str): heap(str.getLength())
	{
		root = nullptr;
		message = str;
		for (int i = 0; i < 256; i++)
		{
			freq[i] = 0;
		}
		setFreq(message);
	}
	void Tree()
	{
		while (heap.getNoOfElements() > 1)
		{
			HuffmanNode* left = heap.remove();
			HuffmanNode* right = heap.remove();

			HuffmanNode* parent = new HuffmanNode();
			parent->symbol = '\0';
			parent->frequency = left->frequency + right->frequency;
			parent->left = left;
			parent->right = right;

			heap.insert(parent);
		}
		root = heap.remove();
		assignCodes(root);
	}
	
};
#endif