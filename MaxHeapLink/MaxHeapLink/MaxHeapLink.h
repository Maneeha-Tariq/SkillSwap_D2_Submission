#ifndef MAXHEAPLINK_H
#define MAXHEAPLINK_H
#include "HNode.h"
#include "Queue.h"
#include<iostream>
using namespace std;
template<typename T>

class MaxHeap
{
	HNode<T>* root;
	int noe;

	void VLR(HNode<T>* p)
	{
		//cout << " hsjhjh";
		cout << p->info << ": ";
		if (p->left)
			VLR(p->left);
		if (p->right)
			VLR(p->right);


	}

public:
	MaxHeap()
	{
		root = nullptr;
		noe = 0;
	}
	void insert(T node)
	{
		if (!root)
		{
			root = new HNode<T>(node);
			noe++;
			return;
		}
		HNode<T>* p = root;
		Queue<HNode<T>*>q;
		q.enQueue(root);
		HNode<T>* newNode = nullptr;

		while (!q.isEmpty())
		{
			HNode<T>* curr = q.deQueue();
			//cout << curr->info << "  ";
			if (curr->left)
				q.enQueue(curr->left);
			else
			{
				curr->left = new HNode<T>(node);
				newNode = curr->left;
				curr->left->par = curr;
				noe++;
				break;
			}
			if (curr->right)
				q.enQueue(curr->right);
			else
			{
				curr->right = new HNode<T>(node);
				newNode = curr->right;
				curr->right->par = curr;
				noe++;
				break;
			}
		}
		HNode<T>* temp = newNode;
		while (temp->par && temp->par->info < temp->info)
		{
			swap(temp->par->info, temp->info);
			temp = temp->par;
		}

	}
	void remove()
	{
		if (!root)
			return;
		if (!root->left && !root->right)
		{
			delete root;
			root = nullptr;
			noe--;
			return;
		}
		//Last element
		Queue<HNode<T>*>q;
		HNode<T>* lastNode;

		q.enQueue(root);
		while (!q.isEmpty())
		{
			HNode<T>* curr = q.deQueue();
			lastNode = curr;
			if (curr->left)
				q.enQueue(curr->left);
			if (curr->right)
				q.enQueue(curr->right);
		}
		//DELETE NODE
		HNode<T>* p = lastNode->par;
		if (p->left == lastNode)
			p->left = nullptr;
		else if (p->right == lastNode)
			p->right = nullptr;
		root->info = lastNode->info;
		delete lastNode;
		noe--;

		//ADJUSTMENT
		HNode<T>* temp = root;

		while (true)
		{
			HNode<T>* largest = temp;

			if (temp->left && temp->left->info > largest->info)
				largest = temp->left;
			if (temp->right && temp->right->info > largest->info)
				largest = temp->right;

			if (largest == temp)
				break;

			swap(temp->info, largest->info);
			temp = largest;
		}




	}
	T getMin()
	{
		return root->info;
	}

	bool search(T node)
	{
		Queue<HNode<T>*>q;

		q.enQueue(root);
		while (!q.isEmpty())
		{
			HNode<T>* curr = q.deQueue();
			if (curr->info == node)
				return 1;
			if (curr->left)
				q.enQueue(curr->left);
			if (curr->right)
				q.enQueue(curr->right);
		}
		return 0;
	}
	void preOrder()
	{
		VLR(root);
	}
	bool isEmpty()
	{
		return root == nullptr;
	}
	T maxHeapTop()
	{
		return root->info;
	}
	int size()
	{
		return noe;
	}
	int Balance()
	{
		HNode<T>* p = root->right;
		HNode<T>* prev = nullptr;

		while (p->left != nullptr)
		{
			prev = p;
			p = p->right;
		}
		int temp = p->info;
		delete p;
		return temp;
	}
};
#endif