#ifndef LSLL_H
#define LSLL_H
#include <iostream>
using namespace std;
#include"Node.h"
#include "Stack.h"
#include "Array.h"
template<typename T>
class LSLL
{
public:
	Node<T>* head;
	bool isEmpty()
	{
		return head == nullptr;
	}
public:
	LSLL() :head(nullptr)
	{
	}
	LSLL(const LSLL<T>& x)
	{
		if (x.head == nullptr)
		{
			head = nullptr;
			return;
		}
		head = new Node<T>(x.head->info);

		Node<T>* src = x.head->next;
		Node<T>* dest = head;
		while (src != nullptr)
		{
			dest->next = new Node<T>(src->info);
			dest = dest->next;
			src = src->next;
		}
	}
	void insertAtHead(T val)
	{
		Node<T>* p = new Node<T>(val);
		p->next = head;
		head = p;
	}
	void insertAtTail(T val)
	{
		Node<T>* p = head;
		if (isEmpty())
		{
			insertAtHead(val);
			return;
		}
		while (p->next != nullptr)
		{
			p = p->next;
		}
		p->next = new Node<T>(val);

	}
	void insertBefore(T key, T val)
	{
		if (isEmpty())
		{
			return;
		}
		Node<T>* p = head;
		if (head->info == key)
		{
			insertAtHead(val);
			return;
		}
		while (p->next && p->next->info != key)
		{
			p = p->next;
		}
		if (p->next)
		{
			Node<T>* x = new Node<T>(val);
			x->next = p->next;
			p->next = x;
		}
	}
	void insertAfter(T key, T val)
	{
		if (isEmpty())
			return;

		Node<T>* p = head;

		while (p && p->info != key)
		{
			p = p->next;
		}

		if (!p)
			return;
		
		Node<T>* x = new Node<T>(val);
		x->next = p->next;
		p->next = x;
	}

	void removeAtHead()
	{
		if (!head)
		{
			return;
		}
		Node<T>* p = head;
		head = head->next;
		delete p;
	}
	void removeAtTail()
	{
		if (isEmpty())
		{
			return;
		}
		if (head->next == nullptr)
		{
			removeAtHead();
			return;
		}
		Node<T>* p = head;
		
		while (p->next->next != nullptr)
		{
			p = p->next;
		}
		Node<T>* q = p->next;
		p->next = nullptr;
		delete q;
	}
	void removeBefore(T key)
	{

		if (isEmpty()|| head->info == key)
		{
			return;
		}
		if (head->next && head->next->info == key)
		{
			removeAtHead();
			return;
		}
		Node<T>* prev = head;
		Node<T>* p = head->next->next;
		while (p && p->info != key)
		{
			p = p->next;
			prev = prev->next;
		}
		if (p != nullptr)
		{
			Node<T>* temp = prev->next;
			prev->next = p;
			delete temp;
		}
	}
	void removeAfter(T key)
	{
		if (isEmpty())
		{
			return;
		}
		Node<T>* p = head;
		while (p && p->info != key)
		{
			p = p->next;
		}
		if (p && p->next)
		{
			Node<T>* toDelete = p->next;
			p->next = toDelete->next;
			delete toDelete;
		}
		
	}
	void remove(T key)
	{
		if (isEmpty())
		{
			return;
		}
		if (head->info == key)
		{
			Node<T>* temp = head;
			head = head->next;
			delete temp;
			return;
		}
		Node<T>* p = head;
		
		while (p->next && p->next->info != key)
		{
			p = p->next;
		}
		if (p->next)
		{
			Node<T>* t = p->next;
			p->next = p->next->next;
			delete t;
		}
	}
	~LSLL()
	{
		while (head)
		{
			removeAtHead();
		}
		head = nullptr;
	}
	void workhousePrint(Node<T>* ptr)
	{
		if (!ptr)
		{
			return;
		}
		cout << ptr->info << " ";
		workhousePrint(ptr->next);

	}
	void print()
	{
		workhousePrint(head);
	}
	void removeDuplicates()
	{
		Node<T>* p = head;
		while (p!=nullptr && p->next != nullptr)
		{
			Node<T>* s = p;
			while (s->next != nullptr)
			{
				if (p->info == s->next->info)
				{
					Node<T>* dup = s->next;
					s->next = s->next->next;
					delete dup;
				}
				else
				{
					s = s->next;
				}
			}
			p = p->next;
		}
	}
	void deleteAlternate()
	{
		Node<T>* p = head;
		while (p != nullptr && p->next != nullptr)
		{
			Node<T>* q = p->next;
			p->next = q->next;
			p = p->next;
			delete q;
		}
	}

	bool isEqual(LSLL<T>& list2)
	{
		if (!head && !list2)
		{
			return true;
		}
		if (!head || !list2)
		{
			return false;
		}
		Node<T>* q = head;
		while (q != nullptr)
		{
			Node<T>* d = list2.head;
			bool flag = false;
			T info = q->info;
			while (d != nullptr)
			{
				if (info == d->info)
				{
					flag = true;
					break;
				}
				d = d->next;
			}
			if (!flag)
			{
				return false;
			}
			q = q->next;
			
		}

		Node<T>* l2 = list2.head;
		while (l2 != nullptr)
		{
			Node<T>* list1 = head;
			bool flag1 = false;
			T info = l2->info;
			while (list1 != nullptr)
			{
				if (info == list1->info)
				{
					flag1 = true;
					break;
				}
				list1 = list1->next;
			}
			if (!flag1)
			{
				return false;
			}
			l2 = l2->next;
		}
		return true;
		
	}

	LSLL<T> doUnion(LSLL<T>& list2)
	{
		LSLL<T> a;
		Node<T>* p = head;
		while (p != nullptr)
		{
			a.insertAtTail(p->info);
			p = p->next;
		}
		Node<T>* q = list2.head;
		
		while (q != nullptr)
		{
			Node<T>* temp = a.head;
			bool exists = false;
			while (temp != nullptr)
			{
				if (q->info == temp->info)
				{
					exists = true;
					break;
					
				}
				temp = temp->next;
			}
			if (!exists)
			{
				a.insertAtTail(q->info);
			}
			q = q->next;
		}
		return a;
	}
	void swap(int m, int n)
	{
		if (m == n) return;

		Node<T>* p = head;
		Node<T>* prevM = nullptr;
		int count = 1;
		while (p != nullptr && count < m)
		{
			prevM = p;
			p = p->next;
			count++;
		}
		
		Node<T>* q = head;
		Node<T>* prevN = nullptr;
		int count1 = 1;
		while (q != nullptr && count1 < n)
		{
			prevN = q;
			q = q->next;
			count1++;
		}
		if (!p || !q)
		{
			return;
		}
		
		if (prevM != nullptr) prevM->next = q;
		else head = q;
		

		if (prevN != nullptr)   prevN->next = p;
		else head = p;
		
		/*if (p->next == q)
		{
			if (prevM) prevM->next = q;
			else head = q;

			p->next = q->next;
			q->next = p;
		}
		else
		{*/
			Node<T>* temp = p->next;
			p->next = q->next;
			q->next = temp;
		/*}*/
	}
	void splitList(LSLL<T>& list1, LSLL<T>& list2)
	{
		if (head == nullptr) return;

		Node<T>* p = head;
		int count = 0;
		while (p != nullptr )
		{
			count++;
			p = p->next;
		}
		Node<T>* q = head;
		if (count % 2 == 0)
		{
			int i = 0;
			while (q != nullptr && i < count / 2)
			{
				T r = q->info;
				list1.insertAtTail(r);
				q = q->next;
				i++;
			}
			int j = 0;
			while (q != nullptr && j < count / 2)
			{
				T r = q->info;
				list2.insertAtTail(r);
				q = q->next;
				j++;
			}
		}
		else
		{
			int i = 0;
			while (q != nullptr && i < (count + 1) / 2)
			{
				T r = q->info;
				list1.insertAtTail(r);
				q = q->next;
				i++;
			}
			int j = 0;
			while (q != nullptr && j < count / 2)
			{
				T r = q->info;
				list2.insertAtTail(r);
				q = q->next;
				j++;
			}

		}
		Node<T> * r = head;
		cout << "Original list: ";
		while (r != nullptr)
		{
			cout << r->info << " ";
			r = r->next;
		}

		cout << "\nList 1: ";
		Node<T> * y = list1.head;
		while (y != nullptr)
		{
			cout << y->info << " ";
			y = y->next;
		}

		cout << "\nList 2: ";
		Node<T>* d = list2.head;
		while (d != nullptr)
		{
			cout << d->info << " ";
			d = d->next;
		}

		while (head != nullptr)
		{
			removeAtHead();
		}
		head = nullptr;
	}
	T findMiddlePoint()
	{
		if (head == nullptr) return T();

		Node<T>* p = head;
		int count = 0;
		while (p != nullptr)
		{
			count++;
			p = p->next;
		}
		if (count % 2 != 0)
		{
			Node<T>* q = head;
			int i = 1;
			while (q != nullptr && i < (count + 1) / 2)
			{
				q = q->next;
				i++; 
			}
			return q->info;
		}
		else
		{
			Node<T>* q = head;
			int i = 1;
			while (q != nullptr && i < count / 2)
			{
				q = q->next;
				i++;
			}
			return q->info;
		}
	}
	void reversePrintRecursively()
	{
		if (!head)
		{
			return;
		}
		if (head->next == nullptr)
		{
			cout << head->info << " ";
			return;
		}
		Node<T>* temp = head;
		head = head->next;
		reversePrintRecursively();
		cout << temp->info<< " ";
		head = temp;
	}
	void reversePrintIteratively()
	{
		if (!head)
		{
			return;
		}
		if (head->next == nullptr)
		{
			cout << head->info << " ";
			return;
		}

		Stack<T> st;
		Node<T>* p = head;
		while (p->next != nullptr)
		{
			st.push(p->info);
			p = p->next;
		}
		cout << p->info << " ";
		while (!st.isEmpty())
		{
			cout << st.pop()<< " ";
		}
	}
	void cyclicAcyclic()
	{
		if (head->next == nullptr)
		{
			cout << "Acyclic\n";
			return;
		}
		if (head->next == head)
		{
			cout << "Cyclic\n";
		}
		Node<T>* p = head;
		while (p->next != nullptr)
		{

		}
	}

		bool isJoiningPoint(LSLL<T> &l)
		{
			Node<T>* l1 = head;
			Node<T>* l2 = l.head;

			if (!l1 || !l2) return false;

			Node<T>* p = head;
			int count = 0;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			Node<T>* q = l.head;
			int count1 = 0;
			while (q != nullptr)
			{
				count1++;
				q = q->next;
			}
			if (count > count1)
			{
				int len =  count - count1  ;
				if (len < 0)
				{
					len = (- 1)*len;
				}
				for (int i = 0; i < len; i++)
				{
					l1 = l1->next;
				}
			}
			else
			{
				int len =  count - count1  ;
				if (len < 0)
				{
					len = (-1) * len;
				}
				for (int i = 0; i < len; i++)
				{
					l2 = l2->next;
				}
			}
			
			while (l1 && l2)
			{
				if (l1 ==  l2)
				{
					return true;
					
				}
				
				l1 = l1->next;
				l2 = l2->next;
			}
			return false;
		}

		T isJoiningPointVal(LSLL<T>& l)
		{
			Node<T>* l1 = head;
			Node<T>* l2 = l.head;

			if (!l1 || !l2)  return T();
			
			Node<T>* p = head;
			int count = 0;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			Node<T>* q = l.head;
			int count1 = 0;
			while (q != nullptr)
			{
				count1++;
				q = q->next;
			}
			if (count > count1)
			{
				int len = count - count1;
				if (len < 0)
				{
					len = (-1) * len;
				}
				for (int i = 0; i < len; i++)
				{
					l1 = l1->next;
				}
			}
			else
			{
				int len = count - count1;
				if (len < 0)
				{
					len = (-1) * len;
				}
				for (int i = 0; i < len; i++)
				{
					l2 = l2->next;
				}
			}

			while (l1 && l2)
			{
				if (l1 == l2)
				{
					return l1->info;

				}

				l1 = l1->next;
				l2 = l2->next;
			}
			return T();
		}
		void sortbylink()
		{
			Node<T>* p = head;

			if (!head) return;
			if (head->next == nullptr) return;
			int posP = 1;
			while (p != nullptr)
			{
				Node<T>* minNode = p;
				Node<T>* q = p->next;
				int posQ = posP+ 1;
				int minP = posP;
				while (q != nullptr)
				{
					if ( q->info < minNode->info)
					{
						minNode = q;
						minP = posQ;

					}
					q = q->next;
					posQ++;
				}
				if (minNode != p)
				{
					swap(posP, minP);
					p = minNode;

				}
				p = p->next;
				posP++;
			}
		}
		void sortbyVal()
		{
			Node<T>* p = head;

			if (!head) return;
			if (head->next == nullptr) return;
			
			while (p != nullptr)
			{
				Node<T>* q = p->next;

				while (q != nullptr)
				{
					if (q->info < p->info)
					{
						T temp = p->info;
						p->info = q->info;
						q->info = temp;

					}
					q = q->next;
				}
				p = p->next;
			}
		}
		LSLL<T> mergeSortedList(LSLL<T> & list2)
		{
			LSLL<T> merge = doUnion(list2);
			merge.sortbyVal();
			return merge;
		}
		void removeRifGreater()
		{
			if (isEmpty()) return;

			Node<T>* p = head;
			Node<T>* q = p->next;
			while (p != nullptr && q != nullptr)
			{
				T val = p->info;
					if (val < q->info)
					{
						p = p->next;
						remove(val);
					}
					else
					{
						p = p->next;
					}
				q = q->next;
			}
		}
		void rearrange()
		{
			Node<T>* p = head;
			Node<T>* q = p->next;
			int count = 0;
			while (p != nullptr && q != nullptr)
			{
				if (count % 2 == 0)
				{
					if (p->info > q->info)
					{
						swap(count + 1, count + 2);
						p = head;
						q = p->next;
						count = 0;
						continue;
					}
				}
				else
				{
					if (p->info < q->info)
					{
						swap(count + 1, count + 2);
						p = head;
						q = p->next;
						count = 0;
						continue;

					}
					
				}

				count++;
				p = p->next;
				q = q->next;
			}
		}
		void findPairs(int x)
		{
			if (head == nullptr)
			{
				return;
			}
			bool find = false;
			Node<T>* p = head;
			while (p != nullptr)
			{
				Node<T>* q = p->next;
				while (q != nullptr)
				{
					int sum = p->info + q->info;
					if (sum == x)
					{
						cout << "(" << q->info << "," << p->info << ")";
						find = true;
					}
					q = q->next;
				}
				p = p->next;
			}
			if (!find)
			{
				cout << "No pair found";
			}
		}
		/*void swapNodeByLink(T node1, T node2)
		{
			
			Node<T>* poi = head;
			Node<T>* poiPrev = nullptr;
			while (poi != nullptr)
			{
				if (poi->info == node1)
				{
					break;
				}
				poiPrev = poi;
				poi = poi->next;
			}
			Node<T>* po1 = head;
			Node<T>* po1Prev = nullptr;
			while (po1 != nullptr)
			{
				if (po1->info == node2)
				{
					break;
				}
				po1Prev = po1;
				po1 = po1->next;
			}
			Node<T>* n1 = poi;
			Node<T>* n2 = po1;
			Node<T>* n1prev = poiPrev;
			Node<T>* n2prev = po1Prev;
			if (!n1 || !n2) return;
			if (n1 == n2) return;
			
			if (n1prev == nullptr)
			{
				head = n2;
			}
			else
			{
				n1prev->next = n2;
			}
				
			if (n2prev == nullptr)
			{
				head = n1;
			}
			else
			{
				n2prev->next = n1;
			}
				
			Node<T>* temp = n1->next;
			n1->next = n2->next;
			n2->next = temp;
			

		}*/
		void reverse()
		{
			Node<T>* prev = nullptr;
			Node<T>* curr = head;
			Node<T>* next = nullptr;

			while (curr != nullptr)
			{
				next = curr->next;   // 1️⃣ next store
				curr->next = prev;   // 2️⃣ link reverse
				prev = curr;         // 3️⃣ prev move
				curr = next;         // 4️⃣ curr move
			}
			head = prev;
		}
		LSLL<T> removeNthNodeFromEnd(LSLL<T>* ptr, int n)
		{
			int count = 0;
			Node<T>* p = ptr->head;
			Node<T>* temp = ptr->head;
			while (p != nullptr)
			{
				count++;
				p = p->next;
			}
			if (n > count)
			{
				return ptr;
			}
			else
			{
				if (count == 1)
				{
					Node<T>* del = ptr->head;
					ptr->head = nullptr;
					delete del;
					return ptr;
				}
				int deleteNode = count - n;
				if (deleteNode == 0)
				{
					Node<T>* del = ptr->head;
					ptr->head = ptr->head->next;
					delete del;
					return ptr;
				}
				while (deleteNode > 1)
				{
					temp = temp->next;
					deleteNode--;
				}
				Node<T>* del = temp->next;
				temp->next = del->next;
				delete del;
				return ptr;
			}
		}
		void insertNodeAtTail(T val)
		{
			Node<T>* p = new Node<T>(val);
			if (head == nullptr)
			{
				head = p;
			}
			else
			{
				Node<T>* temp = head;
				while (temp->next != nullptr)
				{
					temp = temp->next;
				}
				temp->next = p;
				p->next = nullptr;
			}
		}
		LSLL<T>* mergeTwoLists(LSLL<T>* list1, LSLL<T>* list2)
		{
			LSLL<T>* newList = new LSLL<T>();
			
			Node<T>* lis1 = list1->head;
			Node<T>* lis2 = list2->head;
			while (lis1 != nullptr && lis2 != nullptr)
			{
				Node<T>* finalMin = (lis1->info <= lis2->info) ? lis1 : lis2;
				newList->insertNodeAtTail(finalMin->info);
				if (finalMin == lis1)
				{
					lis1 = lis1->next;
				}
				else if (finalMin == lis2)
				{
					lis2 = lis2->next;
				}
			}
			
			while (lis1!= nullptr)
			{
				newList->insertNodeAtTail(lis1->info);
				lis1 = lis1->next;
			}
			
			while (lis2!= nullptr)
			{
				newList->insertNodeAtTail(lis2->info);
				lis2 = lis2->next;
			}
			return newList;
		}
		/*class Solution {
		public:
			ListNode* traverse(ListNode* head)
			{
				if (head == nullptr || head->next == nullptr)
				{
					return head;
				}
				ListNode* first = head;
				while (head->next->next != nullptr)
				{
					head = head->next;
				}
				ListNode* temp = head->next;
				temp->next = first;
				head->next = nullptr;
				first = temp;
				return first;
			}
			ListNode* rotateRight(ListNode* head, int k)
			{
				if (head == nullptr)
				{
					return head;
				}
				if (head != nullptr && head->next == nullptr)
				{
					return head;
				}
				else
				{
					for (int i = k; i > 0; i--)
					{
						ListNode* res = traverse(head);
						head = res;
					}
					return head;
				}
			}
		};*/
};
#endif



/*bool isEqual(LSLL<T>& list2)
	{
		bool flag = true;

		Node<T>* q = head;
		Node<T>* d = list2.head;
		while (q!=nullptr  && d != nullptr )
		{
			if (q->info != d->info )
			{
				flag = false;
				break;
			}

			q = q->next;
			d = d->next;
		}
		if (d == nullptr && q == nullptr && flag == 1)
		{
			return true;
		}
		else
		{
			return false;
		}}*/

/*
void reversePrintIteratively()
{
		if (!head)
		{
			return;
		}
		if (head->next == nullptr)
		{
			cout << head->info << " ";
			return;
		}
		Node<T>* temp = head;
		int count = 1;
		while (temp->next != nullptr)
		{
			count++;
			temp = temp->next;
		}

		Array<T> arr(count);
		Node<T>* q = head;
		int i = 0;
		while (q->next != nullptr)
		{
			arr[i] = q->info;
			q = q->next;
			i++;
		}
		arr[i] = q->info;

		for (int j = count - 1; j >= 0; j--)
		{
			cout << arr[j] << " ";
		}
	}*/

	/*void sortWithLinkSwap()
	{
		if (isEmpty() || head->next == nullptr)
		{
			return;
		}
		Node<T>* p = head;
		int min = head->info;
		int count = 1;
		while (p != nullptr)
		{
			Node<T>* q = p->next;

			while (q != nullptr)
			{
				int curr = q->info;
				if (min > curr)
				{
					swap(count, count+1);
					min = curr;
					count++;
				}
				q = q->next;
			}
			p = p->next;
		}
	}*/


//void remove(T key)
//{
//	if (isEmpty())
//	{
//		return;
//	}
//	if (head->info == key)
//	{
//		Node<T>* temp = head;
//		head = head->next;
//		delete temp;
//		return;
//	}
//	Node<T>* p = head;
//	
//	while (p->next && p->next->info != key)
//	{
//		p = p->next;
//	}
//	if (p->next)
//	{
//		Node<T>* temp = p->next;
//		p->next = temp->next;
//		delete temp;
//	}
//}
//void swapNodes(T key1, T key2)
//{
//	if (key1 == key2)
//	{
//		return;
//	}
//	Node<T>* curr1 = head;
//	Node<T>* prev1 = nullptr;
//	while (curr1 && curr1->info != key1)
//	{
//		prev1 = curr1;
//		curr1 = curr1->next;
//	}
//	Node<T>* curr2 = head;
//	Node<T>* prev2 = nullptr;
//	while (curr2 && curr2->info != key2)
//	{
//		prev2 = curr2;
//		curr2 = curr2->next;
//	}
//	if (!curr1 || !curr2)
//	{
//		return;
//	}
//	if (prev1)
//	{
//		prev1->next = curr2;
//	}
//	else
//	{
//		head = curr2;
//	}
//	if (prev2)
//	{
//		prev2->next = curr1;
//	}
//	else
//	{
//		head = curr1;
//	}
//	if (curr1->next == curr2)
//	{
//		curr1->next = curr2->next;
//		curr2->next = curr1;
//	}
//	else if (curr2->next == curr1)
//	{
//		curr2->next = curr1->next;
//		curr1->next = curr2;
//	}
//	else
//	{
//		Node<T>* temp = curr1->next;
//		curr1->next = curr2->next;
//		curr2->next = temp;
//	}
//
//}