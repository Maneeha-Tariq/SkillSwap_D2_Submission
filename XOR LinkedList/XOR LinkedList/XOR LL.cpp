#include<iostream>
#include <cstdint>
using namespace std;
struct Node
{
	int data;
	Node* npx;
	Node(int d, Node* np = nullptr)
	{
		data = d;
		npx = np;
	}
};
Node* XOR(Node* a, Node* b)
{
	return (Node*)((uintptr_t)(a) ^ (uintptr_t)(b));
}	
class XORLL
{
	Node* head;
	Node* tail;
public:
	XORLL()
	{
		head = tail = nullptr;
	}
	void insertAtHead(int val)
	{
		if (!head)
		{
			head = tail = new Node(val, nullptr);
			return;
		}
		Node* newNode = new Node(val);
		newNode->npx = XOR(nullptr, head);
		Node* next = XOR(nullptr, head->npx);
		head->npx = XOR(newNode, next);
		head = newNode;
	}
	void insertAtTail(int val)
	{
		if (!tail)
		{
			head = tail = new Node(val,nullptr);
			return;
		}
		Node* prev = XOR(nullptr, tail->npx);
		Node* newNode = new Node(val);
		tail->npx = XOR(prev, newNode);
		newNode->npx = XOR(tail, nullptr);
		tail = newNode;
	}
	int removeAtHead()
	{
		int e;
		if (!head)
		{
			cout << "List is Empty\n";
			return -1;
	    }
		else if (head == tail)
		{
			e = head->data;
			delete head;
			head = tail = nullptr;
			return e;
		}
		else
		{
			Node* curr = head;
			Node* nex = XOR(nullptr,curr->npx);
			e = curr->data;
			nex->npx = XOR(nullptr, XOR(curr, nex->npx));
			head = nex;
			delete curr;
			return e;
		}
	}
	int removeAtTail()
	{
		int e;
		if (!tail)
		{
			cout << "List is Empty\n";
			return -1;
		}
		else if (head == tail)
		{
			e = head->data;
			delete head;
			head = tail = nullptr;
			return e;
		}
		else
		{
			e = tail->data;
			Node* curr = tail;
			Node* prev = XOR(nullptr, curr->npx);
			prev->npx = XOR(XOR(tail, prev->npx), nullptr);
			tail = prev;
			delete curr;
			return e;
		}
	}
	bool search(int key)
	{
		if (!head)
		{
			cout << "List is Empty\n";
			return false;
		}
		Node* temp = head;
		Node* prev = nullptr;
		Node* next = nullptr;
		while (temp)
		{
			if (temp->data == key)
			{
				cout << key << " found in list\n";
				return true;
			}
			next = XOR(prev, temp->npx);
			prev = temp;
			temp = next;
		}
		cout << key << " Not found in List\n";
		return false;      
	}
	void print()
	{
		if (!head)
		{
			cout << "List is Empty\n";
			return;
		}
		Node* temp = head;
		Node* prev = nullptr;
		Node* next = nullptr;
		while (temp)
		{
			cout << temp->data << " ";
			next = XOR(prev, temp->npx);
			prev = temp;
			temp = next;
		}
		cout << endl;
	}
	~XORLL()
	{
		Node* curr = head;
		Node* prev = nullptr;
		Node* next = nullptr;
		while (curr)
		{
			next = XOR(prev, curr->npx);
			delete prev;
			prev = curr;
		    curr = next;
		}
		delete prev;
	}
};
int main()
{
	XORLL list;

	list.insertAtHead(1);
	list.insertAtTail(2);
	list.insertAtHead(3);
	list.insertAtTail(4);
	list.insertAtHead(5);

	list.print();  // Expected: 5 3 1 2 4

	list.removeAtTail();
	list.removeAtHead();

	list.print();  // Expected: 3 1 2

	return 0;
}