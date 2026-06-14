#include<iostream>
using namespace std;
struct DLLNode
{
	int data;
	DLLNode* next;
	DLLNode* prev;
	DLLNode(int d, DLLNode* n = nullptr, DLLNode* p = nullptr)
	{
		data = d;
		next = n;
		prev = p;
	}
};
class CDLL
{
	DLLNode* head;
	DLLNode* tail;
public: 
	CDLL()
	{
		head = tail = nullptr;
	}
	void insertAtHead(int e)
	{
		if (!head)
		{
			head = tail = new DLLNode(e);
			head->next = head;
			head->prev = tail;
			return;
		}
		else
		{
			DLLNode* temp = new DLLNode(e, head, tail);

			head->prev = temp;
			head = temp;
			tail->next = head;
		}
	}
	void insertAtTail(int e)
	{
		if (!tail)
		{
			head = tail = new DLLNode(e);
			tail->next = head;
			tail->prev = tail;
			return;
		}
		else
		{
			tail->next = new DLLNode(e, head, tail);
			tail = tail->next;
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
			DLLNode* temp = head;

			head = head->next;
			head->prev = tail;
			tail->next = head;

			delete temp;
		}
		return e;
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
			e = head->data;
			delete head;
			head = tail = nullptr;
		}
		else
		{
			e = tail->data;
			DLLNode* temp = tail;

			tail = tail->prev;
			tail->next = head;
			head->prev = tail;

			delete temp;
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
		DLLNode* temp = head;
		do
		{
			if (temp->data == e)
			{
				if (temp == head)
				{
					deleteFromHead();
				}
				else if (temp == tail)
				{
					deleteFromTail();
				}
				else
				{
					temp->prev->next = temp->next;
					temp->next->prev = temp->prev;
					delete temp;
				}
				return;
			}
			temp = temp->next;
		} while (temp != head);
		cout << "Element not found\n";
		
	}
	void print()
	{
		DLLNode* temp = head;
		if (!temp)
		{
			cout << "List is Empty\n";
			return;
		}
		else
		{
			do
			{
				cout << temp->data;
				if (temp->next != head)
				{
					cout << " -> ";
				}
				temp = temp->next;
			} while (temp != head);
		}
	}


};
int main()
{
	CDLL list;
	list.insertAtTail(10);
	list.insertAtTail(20);
	list.insertAtTail(10);
	list.insertAtTail(30);
	list.deleteANode(10);
	list.print();
}