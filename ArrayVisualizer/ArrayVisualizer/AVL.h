#ifndef BT_H
#include<iostream>
#include "BTNode.h"
#include <queue>
#include "Queue.h"
#include <stack>
using namespace std;
template<typename T>
struct BTANode
{
	T info;
	int h;
	BTANode<T>* left;
	BTANode<T>* right;
	BTANode(T val) :left(nullptr), right(nullptr),h(1)
	{
		info = val;
	}
};
template<typename T>
class AVL
{
	BTANode<T>* root;
	BTANode<T>* searchIt(BTANode<T>* node, T key)
	{
		BTANode<T>* temp = nullptr;
		if (node == nullptr)
			return temp;
		if (node->info == key)
			temp = node;
		if (temp == nullptr && node->left != nullptr)
			temp = searchIt(node->left, key);
		if (temp == nullptr && node->right != nullptr)
			temp = searchIt(node->right, key);
		return temp;
	}
	void LVR(BTANode<T>* node)
	{
		if (node == nullptr)
			return;
		LVR(node->left);
		cout << node->info << " ";
		LVR(node->right);
	}
	void VLR(BTANode<T>* node)
	{
		if (node == nullptr)
			return;
		cout << node->info << " ";
		VLR(node->left);
		VLR(node->right);
	}
	void LRV(BTANode<T>* node)
	{
		if (node == nullptr)
			return;
		VLR(node->left);
		VLR(node->right);
		cout << node->info << " ";
	}
	int getHeight(BTANode<T>* node)
	{
		if (node == nullptr)
			return 0;
		return root->h;
	}
	int max(int a, int b)
	{
		return a >= b ? a : b;
	}
	void printParenthisized(BTANode<T>* node)
	{
		if (node == nullptr)
			return;
		cout << node->info;
		if (node->left != nullptr && node->right != nullptr)
		{
			cout << "(";
			printParenthisized(node->left);
			cout << ",";
			printParenthisized(node->right);
			cout << ")";
		}
	}
	void printExpl(BTANode<T>* curr, int level)
	{
		if (curr == nullptr)
			return;
		if (curr != root)
			cout << '\n';
		for (int i = 0; i < level; i++)
			cout << "\t";
		cout << curr->info;
		printExpl(curr->left, level + 1);
		printExpl(curr->right, level + 1);
	}
	void deleteAll(BTANode<T>* node)
	{
		if (node == nullptr)
			return;
		deleteAll(node->left);
		deleteAll(node->right);
		delete node;
		if (node == root)
			root = nullptr;
	}  // del all lowers of this including this 
	BTANode<T>* getP(BTANode<T>* curr, T key)
	{
		BTANode<T>* temp = nullptr;
		if (curr == nullptr)
			return nullptr;
		if (temp == nullptr && curr->left != nullptr && curr->left->info == key)
			temp = curr->left;
		if (temp == nullptr && curr->left != nullptr)
			temp = getP(curr->left, key);
		if (temp == nullptr && curr->right != nullptr && curr->right->info == key)
			temp = curr->right;
		if (temp == nullptr && curr->right != nullptr)
			temp = getP(curr->right, key);
		return temp;
	}
public:
	AVL()
	{
		root = nullptr;
	}
	T getRoot()
	{
		if (root == nullptr)
			exit(0);
		return root->info;
	}
	T getParent(T node)
	{
		T obj;
		return obj;
	}
	void updateHeights(BTANode<T>* node)
	{
		int hl = (node->left != nullptr) ? node->left->h : 0;
		int hr = (node->right != nullptr) ? node->right->h : 0;
		node->h = 1 + max(hl, hr);
	}
	bool search(T key)
	{
		BTANode<T>* p = root;
		while (p != nullptr)
		{
			if (p->info == key)
				return true;
			else if (p->info <= key)
				p = p->right;
			else
				p = p->left;
		}
		return false;
	}
	void add(T val)
	{
		if (root == nullptr)
			root = new BTANode<T>(val);
		stack<BTANode<T> *> path; 
		BTANode<T>* node = root;
		bool flag = true;
		while (flag)
		{
			path.push(node);
			if (node->info == val)
			{
				return;
			}
			else if (node->info > val)
			{
				if (node->left == nullptr)
				{
					node->left = new BTANode<T>(val);
					flag = false;
				}
				else {
					node = node->left;
				}
			}
			else 
			{
				if (node->right == nullptr)
				{
					node->right= new BTANode<T>(val);
					flag = false;
				}
				else {
					node = node->right;
				}
			}
		}
		// path has all the node passed through
		//BTANode<T>* 
		while (!path.empty())
		{
			BTANode<T> * node=path.top();
			path.pop();
			int hl = 0;
			int hr = 0;
			if (node->left != nullptr) hl = node->left->h;
			if (node->right != nullptr) hr = node->right->h;
			int ht = 1 + max(hl, hr);
			node->h = ht;
			//int ht = 1 + max(hl, hr);
			int lf = hl - hr;
			if (lf == 2)
			{
				// LL or LR 
				
				// for LL
				if (val < node->left->info)
				{
					BTANode<T>* p = node;
					BTANode<T> *lp = node->left;
					BTANode<T>* llp = lp->left;
					lp->right = p;
					if (path.empty()) {
						root = lp;
					}
					else {
						BTANode<T>* tp = path.top();  
						if (tp->left == node)
							tp->left = lp;
						else
							tp->right = lp;
					}
					updateHeights(lp);
				}
				else 
				{
					
					BTANode<T>* p = node;
					BTANode<T>* lp = node->left;
					BTANode<T>* rlp = lp->right;
					BTANode<T>* lrlp = rlp->left;
					BTANode<T>* rrlp = rlp->right;

					rlp->left = p;
					rlp->right = lp;

					p->right = rrlp;
					lp->left = lrlp;
					if (path.empty()) 
					{
						root = rlp;
					}
					else {
						BTANode<T>* tp = path.top();  
						if (tp->left == node)
							tp->left = rlp;
						else
							tp->right = rlp;
					}
					updateHeights(rlp);

				}
			}
			else if (lf == -2)
			{
				// RR
				if (node->right->info < val)
				{
					BTANode<T>* p = node;
					BTANode<T>* rp = node->right;
					BTANode<T>* rrp = rp->right;
					rp->left = p;
					if (path.empty()) 
					{
						root = rp;
					}
					else 
					{
						BTANode<T>* tp = path.top();  
						if (tp->left == node)
							tp->left = rp;
						else
							tp->right = rp;
					}
					updateHeights(rp);
				}
				else
				{
					// LR
					BTANode<T>* p = node;
					BTANode<T>* rp = node->right;
					BTANode<T>* lrp = rp->left;
					BTANode<T>* llrp = lrp->left;
					BTANode<T>* rlrp = lrp->right;

					lrp->left = p;
					lrp->right = rp;
					p->right = llrp;
					rp->left = rlrp;
					if (path.empty()) 
					{
						root = lrp;
					}
					else {
						BTANode<T>* tp = path.top();  // parent of 'node'
						if (tp->left == node)
							tp->left = lrp;
						else
							tp->right = lrp;
					}
					updateHeights(lrp);
				}
			}
		}
	}
	void remove(T key) {
		
		// to be implemented 
	}

	void displayDescendents(T node)
	{
		BTANode<T>* temp = searchIt(root, node);
		if (temp == nullptr)
			return;
		VLR(temp->left);
		VLR(temp->right);
	}
	int heightOfTree()
	{
		return getHeight(root);
	}
	void preOrder()
	{
		VLR(root);
	}
	void postOrder()
	{
		LRV(root);
	}
	void inOrder()
	{
		LVR(root);
	}
	void levelOrder()
	{
		Queue<BTANode<T>*> q;
		if (root != nullptr)
			q.enQueue(root);
		while (!q.isEmpty())
		{
			BTANode<T>* temp = q.deQueue();
			cout << temp->info << " ";
			if (temp->left != nullptr)
				q.enQueue(temp->left);
			if (temp->right != nullptr)
				q.enQueue(temp->right);
		}
	}
	void displayLevel(int ln)
	{
		Queue<BTANode<T>*> q;
		if (root != nullptr)
			q.enQueue(root);
		int cnt = 1;
		while (!q.isEmpty())
		{
			if (cnt == ln)
			{
				int noe = q.getNoOfElements();
				while (noe-- != 0)
					cout << q.deQueue()->info << " ";
				return;

			}
			int noe = q.getNoOfElements();
			while (noe-- != 0)
			{
				BTANode<T>* temp = q.deQueue();

				if (temp->left != nullptr)
					q.enQueue(temp->left);
				if (temp->right != nullptr)
					q.enQueue(temp->right);
			}
			cnt++;
		}
	}
	int findLevelOfNode(T node)
	{
		Queue<BTANode<T>*> q;
		if (root != nullptr)
			q.enQueue(root);
		int cnt = 1;
		while (!q.isEmpty())
		{
			int noe = q.getNoOfElements();
			while (noe-- != 0)
			{
				BTANode<T>* temp = q.deQueue();
				if (temp->info == node)
					return cnt;
				if (temp->left != nullptr)
					q.enQueue(temp->left);
				if (temp->right != nullptr)
					q.enQueue(temp->right);
			}
			cnt++;
		}
		return -1;
	}
	void disPlayParenthesizedView()
	{
		printParenthisized(root);
	}
	void displayExplolarView()
	{
		printExpl(root, 0);
	}
};
#endif // !BT_H
