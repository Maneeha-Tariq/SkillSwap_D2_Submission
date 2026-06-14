#ifndef BST_H
#define BST_H
#include<iostream>
#include "BTNode.h"
#include <queue>
using namespace std;
template<typename T>
class BST
{
	BTNode<T>* root;

	BTNode<T>* searchIt(BTNode<T>* node, T key)
	{
		if (node == nullptr)
			return nullptr;
		if (node->info == key)
			return node;

		if (key < node->info)
			return searchIt(node->left, key);
		return searchIt(node->right, key);
	}

	void LVR(BTNode<T>* node)
	{
		if (node == nullptr)
			return;
		LVR(node->left);
		cout << node->info << " ";
		LVR(node->right);
	}

	void VLR(BTNode<T>* node)
	{
		if (node == nullptr)
			return;
		cout << node->info << " ";
		VLR(node->left);
		VLR(node->right);
	}

	void LRV(BTNode<T>* node)
	{
		if (node == nullptr)
			return;
		LRV(node->left);
		LRV(node->right);
		cout << node->info << " ";
	}

	int getHeight(BTNode<T>* node)
	{
		if (node == nullptr)
			return 0;
		return 1 + max(getHeight(node->left), getHeight(node->right));
	}

	int max(int a, int b)
	{
		return a >= b ? a : b;
	}

	void printParenthisized(BTNode<T>* node)
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

	void printExpl(BTNode<T>* curr, int level)
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

	void deleteAll(BTNode<T>* node)
	{
		if (node == nullptr)
			return;
		deleteAll(node->left);
		deleteAll(node->right);
		delete node;
		if (node == root)
			root = nullptr;
	}

public:

	BST()
	{
		root = nullptr;
	}

	T getRoot()
	{
		if (root == nullptr)
			exit(0);
		return root->info;
	}

	T getParent(T key)
	{
		BTNode<T>* current = root;
		BTNode<T>* parent = nullptr;

		while (current != nullptr)
		{
			if (key == current->info)
			{
				if (parent == nullptr)
				{
					exit(15);
				}

				return parent->info;
			}

			parent = current;

			if (key < current->info)
				current = current->left;
			else
				current = current->right;
		}

		cout << "Key does not in BST!";
		exit(15);
	}

	bool search(T key)
	{
		BTNode<T>* p = root;
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
		{
			root = new BTNode<T>(val);
			return;
		}
		BTNode<T>* node = root;
		while (true)
		{
			if (node->info <= val)
			{
				if (node->right == nullptr)
				{
					node->right = new BTNode<T>(val);
					return;
				}
				else node = node->right;
			}
			else
			{
				if (node->left == nullptr)
				{
					node->left = new BTNode<T>(val);
					return;
				}
				else node = node->left;
			}
		}
	}

	void remove(T key)
	{
		if (root == nullptr)
			return;

		// case: root deletion
		if (root->info == key)
		{
			if (root->left == nullptr && root->right == nullptr)
			{
				BTNode<T>* todel = root;
				root = nullptr;
				delete todel;
				return;
			}
			else if ((root->left == nullptr) || (root->right == nullptr))
			{
				BTNode<T>* todel = root;
				root = (root->left != nullptr) ? root->left : root->right;
				delete todel;
				return;
			}
			else
			{
				BTNode<T>* succ = root->right;
				BTNode<T>* succP = root;

				while (succ->left != nullptr)
				{
					succP = succ;
					succ = succ->left;
				}

				root->info = succ->info;

				if (succP->left == succ)
					succP->left = succ->right;
				else
					succP->right = succ->right;

				delete succ;
				return;
			}
		}

		// non-root delete
		BTNode<T>* curr = root;
		BTNode<T>* par = root;

		while (curr != nullptr)
		{
			if (curr->info == key)
			{
				BTNode<T>* todel = curr;

				// leaf
				if (curr->left == nullptr && curr->right == nullptr)
				{
					if (par->left == curr) par->left = nullptr;
					else par->right = nullptr;
					delete todel;
					return;
				}
				// one child
				else if ((curr->left == nullptr) || (curr->right == nullptr))
				{
					BTNode<T>* child = (curr->left != nullptr) ? curr->left : curr->right;

					if (par->left == curr) par->left = child;
					else par->right = child;

					delete todel;
					return;
				}
				// two children
				else
				{
					BTNode<T>* succ = curr->right;
					BTNode<T>* succP = curr;

					while (succ->left != nullptr)
					{
						succP = succ;
						succ = succ->left;
					}

					curr->info = succ->info;

					if (succP->left == succ)
						succP->left = succ->right;
					else
						succP->right = succ->right;

					delete succ;
					return;
				}
			}
			else if (curr->info < key)
			{
				par = curr;
				curr = curr->right;
			}
			else
			{
				par = curr;
				curr = curr->left;
			}
		}
	}

	void displayDescendents(T node)
	{
		BTNode<T>* temp = searchIt(root, node);
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
		queue<BTNode<T>*> q;

		if (root != nullptr)
			q.push(root);

		while (!q.empty())
		{
			BTNode<T>* temp = q.front();
			q.pop();

			cout << temp->info << " ";

			if (temp->left != nullptr)
				q.push(temp->left);
			if (temp->right != nullptr)
				q.push(temp->right);
		}
	}

	int findLevelOfNode(T node)
	{
		queue<BTNode<T>*> q;

		if (root != nullptr)
			q.push(root);

		int cnt = 1;

		while (!q.empty())
		{
			int noe = q.size();

			while (noe-- != 0)
			{
				BTNode<T>* temp = q.front();
				q.pop();

				if (temp->info == node)
					return cnt;

				if (temp->left != nullptr)
					q.push(temp->left);
				if (temp->right != nullptr)
					q.push(temp->right);
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

#endif
