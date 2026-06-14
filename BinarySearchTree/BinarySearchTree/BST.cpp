#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int val)
	{
		data = val;
		left = right = nullptr;
	}
};
Node* insertIterative(Node* root, int val)
{
	if (!root)
	{
		root = new Node(val);
		return root;
	}
	Node* curr = root;
	Node* prev = nullptr;
	while (curr != nullptr)
	{
		if (val < curr->data)
		{
			prev = curr;
			curr = curr->left;
		}
		else if (curr->data == val)
		{
			cout << "Value already exists\n";
			return root;
		}
		else
		{
			prev = curr;
			curr = curr->right;
		}
	}
	if (val < prev->data)
	{
		prev->left = new Node(val);
	}
	else if (val > prev->data)
	{
		prev->right = new Node(val);
	}
	return root;
}
bool search(int val, Node* root)
{
	if (!root)
	{
		return false;
	}
	Node* curr = root;
	while (curr != nullptr)
	{
		if (val < curr->data)
		{
			curr = curr->left;
		}
		else if (curr->data == val)
		{
			cout << "found\n";
			return true;
		}
		else
		{
			curr = curr->right;
		}
	}
	cout << "Not found\n";
	return false;
}
Node* deleteTwoChild(Node* root, Node* curr)
{
	Node* succParent = curr;
	Node* succ = curr->right;
	while (succ->left != nullptr)
	{
		succParent = succ;
		succ = succ->left;
	}
	curr->data = succ->data;
	if (succParent->left == succ)
	{
		succParent->left = succ->right;
	}
	else
	{
		succParent->right = succ->right;
	}
	delete succ;
	return root;
}
Node* deleteNode(Node* root, int key)
{
	if (!root)
	{
		cout << "Tree is Empty\n";
		return root;
	}
	Node* prev = nullptr;
	Node* curr = root;
	while (curr != nullptr)
	{
		if (key < curr->data)
		{
			prev = curr;
			curr = curr->left;
		}
		else if (curr->data == key)
		{
			if (prev == nullptr)
			{
				if (!curr->left && !curr->right)
				{
					delete curr;
					return nullptr;
				}
				else if((!curr->left && curr->right) || (curr->left && !curr->right))
				{
					Node* child = (curr->left) ? curr->left : curr->right;
					delete curr;
					return child;
				}
				else
				{
					return deleteTwoChild(root, curr);
				}
			}
			if (!curr->left && !curr->right)
			{
				if (prev->left == curr)
				{
					prev->left = nullptr;
					delete curr;
				}
				else if (prev->right == curr)
				{
					prev->right = nullptr;
					delete curr;
				}
				return root;
			}
			else if ((!curr->left && curr->right) || (curr->left && !curr->right))
			{
				if (prev->left == curr)
				{
					if (curr->left)
					{
						prev->left = curr->left;
						delete curr;
					}
					else if (curr->right)
					{
						prev->left = curr->right;
						delete curr;
					}
					return root;
				}
				else if(prev->right == curr)
				{
					if (curr->left)
					{
						prev->right = curr->left;
						delete curr;
					}
					else if (curr->right)
					{
						prev->right = curr->right;
						delete curr;
					}
					return root;
				}
			}
			else
			{
				return deleteTwoChild(root, curr);
			}
		}
		else
		{
			prev = curr;
			curr = curr->right;
		}
	}
	return root;
}
void inorder(Node* root)
{
	if (!root) return;
	inorder(root->left);
	cout << root->data << " ";
	inorder(root->right);
}
bool isBSTUtil(Node* root, Node* minNode, Node* maxNode) {
	if (root == nullptr)
		return true;

	// check lower bound
	if (minNode != nullptr && root->data <= minNode->data)
		return false;

	// check upper bound
	if (maxNode != nullptr && root->data >= maxNode->data)
		return false;

	return isBSTUtil(root->left, minNode, root) &&
		isBSTUtil(root->right, root, maxNode);
}

bool checkBST(Node* root) {
	return isBSTUtil(root, nullptr, nullptr);
}

int main()
{
	int arr[] = { 1,4,9,5,10,3,7 };
	Node* root = nullptr;
	for (int i = 0; i < 7; i++)
	{
		root = insertIterative(root,arr[i]);
	}
	inorder(root);
}