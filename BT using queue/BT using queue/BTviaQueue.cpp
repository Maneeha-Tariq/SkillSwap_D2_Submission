#include<iostream>
#include<queue>
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
Node* BinaryTree()
{
	int x; int first; int sec;
	cout << "Enter the root Element: ";
	cin >> x;
	Node* root = new Node(x);
	queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		cout << "Enter the left child of " << temp->data << " : ";
		cin >> first;
		if (first != -1)
		{
			temp->left = new Node(first);
			q.push(temp->left);
		}
		cout << "Enter the right child of " << temp->data << " : ";
		cin >> sec;
		if (sec != -1)
		{
			temp->right = new Node(sec);
			q.push(temp->right);
		}
	}
	return root;
}
void levelOrderQueue(Node* t)
{
	queue<Node*> temp;
	temp.push(t);
	while (!temp.empty())
	{
		Node* newNOde = temp.front();
		temp.pop();
		cout << newNOde->data<< " ";
		if (newNOde->left)
		{
			temp.push(newNOde->left);
		}
		if (newNOde->right)
		{
			temp.push(newNOde->right);
		}
	}
}
Node* BinaryTreeLL()
{
	int x;
	cin >> x;
	if (x == -1)
	{
		return nullptr;
	}
	Node* temp = new Node(x);
	cout << "Enter the left child of " << temp->data << " : ";
	temp->left = BinaryTreeLL();
	cout << "Enter the right child of " << temp->data << " : ";
	temp->right = BinaryTreeLL();
	return temp;
}
int sizeOfTreeIter(Node* root)
{
	if (root == nullptr)
	{
		cout << "Tree has no nodes\n";
		return -1;
	}
	int count = 0;
	queue<Node*>q;
	q.push(root);
	Node* temp;
	while (!q.empty())
	{
		temp = q.front();
		q.pop();
		count++;
		if (temp->left)
			q.push(temp->left);
		if (temp->right)
			q.push(temp->right);
	}
	return count;
}
int sizeOfTreeRec(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	return 1 + sizeOfTreeRec(root->left) + sizeOfTreeRec(root->right);
}
void sum(Node* tree, int& count)
{
	if (tree == nullptr)
	{
		return;
	}
	count += tree->data;
	sum(tree->left,count);
	sum(tree->right, count);
}
int sumOfBinaryTree(Node* tree)
{
	int count = 0;
	sum(tree, count);
	return count;
}
void countLeaf(Node* root, int& count)
{
	if (root == nullptr) return;
	if (!root->left && !root->right)
	{
		count++;
		return;
	}
	countLeaf(root->left,count);
	countLeaf(root->right, count);
}
int countLeafNode(Node* root)
{
	int count = 0;
	countLeaf(root, count);
	return count;
}
int countLeafByWithoutVar(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	if (!root->left && !root->right)
	{
		return 1;
	}
	return countLeafByWithoutVar(root->left) + countLeafByWithoutVar(root->right);
}
int width(Node* root)
{
	if (root == NULL)
		return 0;

	queue<Node*> q;
	q.push(root);

	int maxWidth = 0;

	while (!q.empty())
	{
		int count = q.size();

		maxWidth = max(maxWidth, count);

		while (count--)
		{
			Node* temp = q.front();
			q.pop();

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
	}

	return maxWidth;

}
vector<int> largestElementInEachLevel(Node* root)
{
	queue<Node*>q;
	q.push(root);
	vector<int>res;
	while (!q.empty())
	{
		int s = q.size();
		int max = q.front()->data;
		while (s > 0 && !q.empty())
		{
			Node* t = q.front();
			q.pop();

			if (t->data > max)
			   max = t->data;
			if (t->left)
				q.push(t->left);
			if (t->right)
				q.push(t->right);
			s--;
		}
		res.push_back(max);
	}
	return res;
}
void LVR(Node* t)
{
	if (t == nullptr)
	{
		return;
	}
	LVR(t->left);
	cout << t->data << " ";
	LVR(t->right);
}
void VLR(Node* t)
{
	if (t == nullptr)
	{
		return;
	}
	cout << t->data << " ";
	LVR(t->left);
	LVR(t->right);
}
void LRV(Node* t)
{
	if (t == nullptr)
	{
		return;
	}
	LVR(t->left);
	LVR(t->right);
	cout << t->data << " ";
}
void countCompHelper(Node* root, int& count)
{
	queue<Node*>q;
	q.push(root);
	while (!q.empty())
	{
		Node* temp = q.front();
		q.pop();
		if (temp->left && !temp->right)
		{
			count++;
			q.push(temp->left);
		}
		if (temp->right && !temp->left)
		{
			count++;
			q.push(temp->right);
		}
	}
}
// compression level is 1 if the node has only one child either left or right 
int countCompressionLevel(Node* root)
{
	int count = 0;
	countCompHelper(root, count);
	return count;
}
bool isIsomorphic(Node* root1, Node* root2)
{
	if (!root1 && !root2)
	{
		return 1;
	}
    if ((root1 && !root2)|| (!root1&& root2))
	{
		return 0;
	}
	if (root1->data != root2->data)
	{
		return 0;
	}
	return(
		    (isIsomorphic(root1->left, root2->left) &&
			isIsomorphic(root1->right, root2->right))
		    ||
		    (isIsomorphic(root1->right, root2->left) &&
			isIsomorphic(root1->left, root2->right))
		);
}
int moves = 0;

int dfs(Node* root)
{
	if (root == NULL)
		return 0;

	// postorder: left → right → node
	int left = dfs(root->left);
	int right = dfs(root->right);

	// count moves for this node
	moves += abs(left) + abs(right);

	// return balance to parent
	return root->data + left + right - 1;
}
int distributeCoins(Node* root)
{
	dfs(root);
	return moves;
}
int main()
{
	/*Node* t = BinaryTreeLL();
	vector<int> v = largestElementInEachLevel(t);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/
	Node* t = BinaryTree();
	Node* t2 = BinaryTree();
	cout << endl;
	cout << isIsomorphic(t, t2);
	return 0;
}
