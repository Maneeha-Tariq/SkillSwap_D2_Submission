#include<iostream>
using namespace std;
struct Node
{
	int data;
	Node* next;
	Node(int d, Node* n = nullptr)
	{
		data = d;
		next = n;
	}
};
class CSLL
{
	Node* head;
	Node* tail;
public:
	CSLL()
	{
		head = tail = nullptr;
	}
	void insertAtHead(int e)
	{
		if (!head)
		{
			head = tail = new Node(e);
			tail->next = head;
		}
		else
		{
			Node* temp = new Node(e);
			temp->next = head;
			head = temp;
			tail->next = head;
		}
	}
	void insertAtTail(int e)
	{
		if (!tail)
		{
			head = tail = new Node(e);
			tail->next = head;
		}
		else
		{
			tail->next = new Node(e,head);
			tail = tail->next;
		}
	}
	int deleteFromTail()
	{
		int e;
		if (!tail)
		{
			cout << "List is Empty\n";
			return -1;
		}
		else if (head == tail)
		{
			e = tail->data;
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			Node* temp = head;
			while (temp->next != tail)
			{
				temp = temp->next;
			}
			e = tail->data;
			delete tail;
			temp->next = head;
			tail = temp;
			
		}
		return e;
	}
	int deleteFromHead()
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
		}
		else
		{
			e = head->data;
			Node* temp = head;
			head = head->next;
			delete temp;
			tail->next = head;
		}
		return e;
	}
	void deleteANode(int e)
	{
		if (!head)
		{
			cout << "List is Empty\n";
			return;
		}
		else if (head->data == e)
		{
			deleteFromHead();
			return;
		}
		else if (tail && tail->data == e)
		{
			deleteFromTail();
			return;
		}
		else
		{
			Node* temp = head;
			do
			{
				if (temp->next->data == e)
				{
					Node* toDelete = temp->next;
					temp->next = toDelete->next;
					delete toDelete;
					return;
				}
				temp = temp->next;
			} while (temp != head);
			
			cout << "Element not found\n";
		}
	}

};