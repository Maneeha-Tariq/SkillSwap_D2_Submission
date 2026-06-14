#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include<iostream>
#include<cmath>
#include "Queue.h"
using namespace std;
template<typename T>
class BinaryTree
{
	int maxHeight;
	T* data;
	bool* nodeStatus;
	int arrayCapacity;

	int search(int i, T key)
	{
		if (i >= arrayCapacity || !nodeStatus[i])
			return -1;
		int index = -1;
		if (data[i] == key)
		{
			index = i;
		}
		if (index == -1 && 2 * i + 1 < arrayCapacity && nodeStatus[2 * i + 1])
		{
			index = search(2 * i + 1, key);
		}
		if (index == -1 && 2 * i + 2 < arrayCapacity && nodeStatus[2 * i + 2])
		{
			index = search(2 * i + 2, key);
		}
		return index;
	}
	

	
	void VLR(int i,bool first = true)
	{
		if (i >= arrayCapacity || !nodeStatus[i]) return;  // check current node
		if (!first)
		{
			cout << ",";
		}
		cout << data[i]<< " ";
		if (2 * i + 1 < arrayCapacity && nodeStatus[2 * i + 1])
		{
			VLR(2 * i + 1,false);
		}
		if (2 * i + 2 < arrayCapacity && nodeStatus[2 * i + 2])
		{
			VLR(2 * i + 2,false);
		}
	}
	void LRV(int i)
	{
		if(i >= arrayCapacity || !nodeStatus[i]) return;
		if (2 * i + 1 < arrayCapacity && nodeStatus[2 * i + 1])
		{
			LRV(2 * i + 1);
		}
		if (2 * i + 2 < arrayCapacity && nodeStatus[2 * i + 2])
		{
			LRV(2 * i + 2);
		}
		cout << data[i] << ",";
	}
	void LVR(int i, bool first = true)
	{
		if (i >= arrayCapacity || !nodeStatus[i]) return;
		if (2 * i + 1 < arrayCapacity && nodeStatus[2 * i + 1])
		{
			LVR(2 * i + 1,first);
		}
		if (!first)
		{
			cout << ",";
		}
			cout << data[i];
		if (2 * i + 2 < arrayCapacity && nodeStatus[2 * i + 2])
		{
			LVR(2 * i + 2,false);
		}
		
	}
	int max(int l, int r)
	{
		return (l > r) ? l : r;
	}
	
	
	
	void parenthesizedView(int index)
	{
		if (index >= arrayCapacity || !nodeStatus[index])
			return;

		cout << data[index];

		int left = 2 * index + 1;
		int right = 2 * index + 2;

		bool hasLeft = (left < arrayCapacity && nodeStatus[left]);
		bool hasRight = (right < arrayCapacity && nodeStatus[right]);

		if (hasLeft || hasRight)
		{
			cout << "(";
			if (hasLeft)
				parenthesizedView(left);

			if (hasRight)
			{
				if (!hasLeft)
					cout << ""; // no left child, nothing before comma
				cout << ",";
				parenthesizedView(right);
			}
			cout << ")";
		}
	}

	void explorerView(int index, int level = 0)
	{
		if (index >= arrayCapacity || !nodeStatus[index])
			return;

		for (int i = 0; i < level; i++)
			cout << "\t";

		cout << data[index] << "\n";

		int left = 2 * index + 1;
		int right = 2 * index + 2;

		if (left < arrayCapacity && nodeStatus[left])
			explorerView(left, level + 1);
		if (right < arrayCapacity && nodeStatus[right])
			explorerView(right, level + 1);
	}



public:
	BinaryTree(int h)
	{
		arrayCapacity = pow(2, h) - 1;
		maxHeight = h;
		data = new T[arrayCapacity];
		nodeStatus = new bool[arrayCapacity];
		for (int i = 0; i < arrayCapacity; i++)
		{
			nodeStatus[i] = false;
		}
	}
	void setRoot(T v)
	{
		if (arrayCapacity > 0)
		{
			data[0] = v;
			nodeStatus[0] = true;
		}
	}
	T getRoot()
	{
		if (!data[0])
		{
			return T();
		}
		return data[0];
	}
	void setLeftChild(T parent, T child)
	{
		int index = search(0, parent);
		if (index == -1) return;

		if (index != -1 && 2*index+1 < arrayCapacity)
		{
			data[2 * index + 1] = child;
			nodeStatus[2 * index + 1] = true;
		}
	}
	void setRightChild(T parent, T child)
	{
		int index = search(0, parent);
		if (index == -1)  return;

		if (index != -1 && 2*index+2 < arrayCapacity)
		{
			data[2 * index + 2] = child;
			nodeStatus[2 * index + 2] = true;
		}
	}
	T getParent(T node)
	{
		int index = search(0, node);
		if (index == -1) return T();

		int i = (index - 1) / 2;
		return data[i];
	}
	void remove(T node)
	{
		int index = search(0, node);
		if (index == -1) return;

		nodeStatus[index] = false;
		if (index != -1 && 2 * index + 1 < arrayCapacity)
		{
			T d = data[2 * index + 1];
			remove(d);
		}
		if (index != -1 && 2 * index + 2 < arrayCapacity)
		{
			T d = data[2 * index + 2];
			remove(d);
		}
	}
	void displayDescendents(T node)
	{
		int index = search(0, node);
		if (index == -1) return;

		if (index != -1 && 2 * index + 1 < arrayCapacity)
		{
			T d = data[2 * index + 1];
			cout << d << ",";
			displayDescendents(d);
		}
		if (index != -1 && 2 * index + 2 < arrayCapacity)
		{
			T d = data[2 * index + 2];
			cout << d << ",";
			displayDescendents(d);
		}
	}
	void displayAncestors(T node)
	{
		int index = search(0, node);
		int parentNode = (index - 1) / 2;
		if (index == -1) return;

		if (index != -1 && parentNode < arrayCapacity)
		{
			T temp = data[parentNode];
			cout << temp << ",";
			displayAncestors(temp);
		}
	}
	int heightOfTree(int i)
	{
		if (i >= arrayCapacity || !nodeStatus[i])
			return 0;

		int left = 0, right = 0;
		if (2 * i + 1 < arrayCapacity && nodeStatus[2 * i + 1])
		{
			left = heightOfTree(2 * i + 1);
		}
		if (2 * i + 2 < arrayCapacity && nodeStatus[2 * i + 2])
		{
			right = heightOfTree(2 * i + 2);
		}
		return 1 + max(left, right);
	}
	void preOrder()
	{
		VLR(0);
	}
	void postOrder()
	{
		LRV(0);
	}
	void inOrder()
	{
		LVR(0);
	}
	void levelOrder()
	{
		Queue<int> q;
		int i = 0;
		if (i < arrayCapacity)
		{
			q.enQueue(i);
		}
		while (!q.isEmpty())
		{
			int curr = q.deQueue();
			if (curr!=0)
			{
				cout << ",";
			}
			cout << data[curr];
		    if (2 * curr + 1 < arrayCapacity && nodeStatus[2 * curr + 1])
			{
				q.enQueue(2 * curr + 1);
			}
			if (2 * curr + 2 < arrayCapacity && nodeStatus[2 * curr + 2])
			{
				q.enQueue(2 * curr + 2);
			}
			
		}
	}
	void displayLevel(int levelNo)
	{
		int i = pow(2, levelNo) - 1;
		int j = i;
		bool first = true;
		for (; i <= 2 * j && i < arrayCapacity; i++)
		{
			if (nodeStatus[i])
			{
				if (!first) cout << ",";
				cout << data[i];
				first = false;
			}
		}
	}
	int findLevelOfNode(T node)
	{
		int index = search(0, node);
		if (index == -1) return -1;
		
		return (int)floor(log2(index + 1));
	}
	void displayParenthesizedView()
	{
		parenthesizedView(0);
		
	}
	void displayExplorerView()
	{
		explorerView(0);
	}
	

};
#endif



//



