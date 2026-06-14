#ifndef BT_NODE_H
#define BT_NODE_H
template<typename T>
struct BTNode
{
	T info;
	BTNode<T>* left;
	BTNode<T>* right;
	BTNode(T val) :left(nullptr), right(nullptr)
	{
		info = val;
	}
};
#endif // !BT_NODE_H
