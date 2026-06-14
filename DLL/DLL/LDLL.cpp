#include<iostream>
using namespace std;
struct DLLNode
{
	int data;
	DLLNode* next;
	DLLNode* prev;
	DLLNode(int d, DLLNode* n=nullptr, DLLNode* p=nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
};
class DLList
{
	DLLNode* head;
	DLLNode* tail;
public:
	DLList()
	{
		head = tail = nullptr;
	}
	void addToDLLTail(int e)
	{
		if (!tail)
		{
			head = tail = new DLLNode(e);
			return;
		}
		else
		{
			tail = new DLLNode(e, nullptr, tail);
			tail->prev->next = tail;
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
		else if(head==tail)
		{
			e = tail->data;
			delete tail;
			head = tail = nullptr;
		}
		else
		{
			e = tail->data;
			tail = tail->prev;
			delete tail -> next;
			tail->next = nullptr;
		}
		return e;
	}
	void addToHead(int e)
	{
		if (!head)
		{
			tail = head = new DLLNode(e);
			return;
		}
		else
		{
			head->prev = new DLLNode(e,head,nullptr);
			head = head->prev;
		}
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
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			
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
		}
		else if (tail && tail->data == e)
		{
			deleteFromTail();
		}
		else
		{
			DLLNode* temp = head;
			while (temp != nullptr && temp->data != e)
			{
				temp = temp->next;
			}
			if (temp)
			{
				if (temp->prev)
				{
					temp->prev->next = temp->next;
				}
				if (temp->next != nullptr)
				{
					temp->next->prev = temp->prev;
				}
				delete temp;
			}
			else
			{
				cout << "Element not Found\n";
			}
		}
	}
	void print()
	{
		DLLNode* temp = head;
		while (temp != nullptr)
		{
			cout << temp->data;
			if (temp->next != nullptr)
			{
				cout << " -> ";
			}
			temp = temp->next;
		}
	}
};
int main()
{
	DLList list;
	list.addToDLLTail(20);
	list.addToDLLTail(30);
	list.addToDLLTail(40);
	list.deleteFromTail();
	list.deleteFromTail();
	list.deleteFromTail();
	list.addToDLLTail(50);
	list.print();

}