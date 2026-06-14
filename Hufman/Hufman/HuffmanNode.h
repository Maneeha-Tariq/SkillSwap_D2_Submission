#ifndef HUFFMAN_NODE_H
#define HUFFMAN_NODE_H
#include<iostream>
using namespace std;
struct HuffmanNode
{
	char symbol;
	double frequency;
	double probability;
	String code;
	HuffmanNode* left;
	HuffmanNode* right;

	HuffmanNode()
	{
		symbol = ' ';
		frequency = 0.0;
		probability = 0.0;
		left = nullptr;
		right = nullptr;
	}
	HuffmanNode(char ch, int freq)
	{
		symbol = ch;
		frequency = freq;
		left = nullptr;
		right = nullptr;
	}
};
#endif