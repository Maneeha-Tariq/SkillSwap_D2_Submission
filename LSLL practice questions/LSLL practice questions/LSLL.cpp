#include<iostream>
using namespace std;
#include<stack>
template<typename T>
struct Node
{
	T data;
	Node* next;
	Node()
	{
		data = 0;
		next = nullptr;
	}
	Node(T d, Node* ptr = nullptr)
	{
		data = d;
		next = ptr;
	}
};
template<typename T>
class SinglyLList
{
	Node<T>* head;
	Node<T>* tail;
public:
	SinglyLList()
	{
		head = nullptr;
		tail = nullptr;
	}
	void insertAtHead(T val)
	{
		Node<T>* ptr = new Node<T>(val, head);
		if (isEmpty())
		{
			head = tail = ptr;
		}
		else
		{
			head = ptr;
		}
	}
	void insertAtTail(T val)
	{
		Node<T>* ptr = new Node<T>(val);
		if (isEmpty())
		{
			head = tail = ptr;
		}
		else
		{
			tail->next = ptr;
			tail = ptr;
		}
	}
	T deleteAtHead()
	{
		int val;
		if (isEmpty())
		{
			cout << "List is Empty\n";
			exit(0);
		}
		else
		{
			if (head == tail)
			{
				Node<T>* temp = head;
				val = temp->data;
				delete temp;
				head = tail = nullptr;
			}
			else
			{
				Node<T>* temp = head;
				val = temp->data;
				head = head->next;
				delete temp;
			}
		}
		return val;
	}
	T deleteAtTail()
	{
		int val;
		if (isEmpty())
		{
			cout << "List is Empty\n";
			exit(0);
		}
		else
		{
			if (head == tail)
			{
				Node<T>* temp = tail;
				val = temp->data;
				delete temp;
				head = tail = nullptr;
			}
			else
			{
				Node<T>* temp = head;
				while (temp->next != tail)
				{
					temp = temp->next;
				}
				Node<T>* toDelete = tail;
				val = toDelete->data;
				temp->next = nullptr;
				tail = temp;
				delete toDelete;
			}
		}
		return val;
	}
	bool isEmpty()
	{
		return head == nullptr;
	}
	void print()
	{
		if (isEmpty())
		{
			cout << "List is Empty\n";
			return;
		}
		else
		{
			Node<T>* temp = head;
			while (temp->next != nullptr)
			{
				cout << temp->data << " -> ";
				temp = temp->next;
			}
			cout << temp->data;
		}
	}
	Node<T>* buildWordList(string s)
	{
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			while (i < n && s[i] == ' ')
			{
				i++;
			}
			if (i >= n)
			{
				break;
			}
			string newWord = " ";
			while (s[i] != ' ' && s[i] != '\0')
			{
				newWord += s[i];
				i++;
			}
			if (!newWord.empty())
			{
				insertAtTail(newWord);
			}
		}
		return head;
	}

	Node<T>* getHead()
	{
		return head;
	}

};
Node<int>* rotateRight(Node<int>* head, int k)
{
	if (!head || k == 0)
	{
		return head;
	}
	int count = 0;
	Node<int>* temp = head;
	while (temp->next != nullptr)
	{
		count++;
		temp = temp->next;
	}
	count = count + 1;
	temp->next = head;
	Node<int>* newHead = head;
	Node<int>* tail = head;
	k = k % count;
	if (k == 0)
	{
		temp->next = nullptr;
		return head;
	}
	int newTail = count - k - 1;
	for (int i = 0; i < newTail; i++)
	{
		tail = tail->next;
	}
	newHead = tail->next;
	tail->next = nullptr;
	return newHead;
}

Node<int>* reverse(Node<int>* head)
{
	Node<int>* prev = nullptr;
	Node<int>* curr = head;
	Node<int>* nex;
	while (curr != nullptr)
	{
		nex = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nex;
	}
	return prev;
}

void reorderList(Node<int>* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return;
	}
	Node<int>* slow = head;
	Node<int>* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	Node<int>* temp1 = head;

	Node<int>* secHalf = slow->next;
	secHalf = reverse(secHalf);
	slow->next = nullptr;
	Node<int>* t1 = temp1;
	Node<int>* t2 = secHalf;
	while (t1 != nullptr && t2 != nullptr)
	{
		Node<int>* firstnext = t1->next;
		t1->next = t2;
		Node<int>* secnext = t2->next;
		t2->next = firstnext;
		t1 = firstnext;
		t2 = secnext;
	}
}
Node<int>* sort(Node<int>* head)
{
	if (head == nullptr || head->next == nullptr)
	{
		return head;
	}
	Node<int>* slow = head;
	Node<int>* fast = head;
	Node<int>* prev = nullptr;
	while (fast != nullptr && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	Node<int>* secHalf = slow;
	prev->next = nullptr;
	Node<int>* temp = head; Node<int>* res = nullptr;
	Node<int>* finalAns = nullptr;
	while (temp != nullptr && secHalf != nullptr)
	{
		if (temp->data < secHalf->data)
		{
			if (!res)
			{
				res = temp;
				finalAns = res;
			}
			else
			{
				res->next = temp;
				res = res->next;
			}
			temp = temp->next;
		}
		else
		{
			if (!res)
			{
				res = secHalf;
				finalAns = res;
			}
			else
			{
				res->next = secHalf;
				res = res->next;
			}
			secHalf = secHalf->next;
		}
	}
	if (temp != nullptr)
	{
		while (temp != nullptr)
		{
			res->next = temp;
			res = res->next;
			temp = temp->next;
		}
	}
	else
	{
		while (secHalf != nullptr)
		{
			res->next = secHalf;
			res = res->next;
			secHalf = secHalf->next;
		}
	}
	return finalAns;

}
Node<int>* reverseSublist(Node<int>* head, int l, int r)
{
	if (!head)
	{
		return head;
	}
	Node<int>* prevL=nullptr; Node<int>* sublist=nullptr; Node<int>* afterR=nullptr;
	Node<int>* temp = head;
	while (temp != nullptr)
	{
		if (l > 1)
		{
			if (!prevL)
			{
				prevL = temp;
			}
			else
			{
				prevL->next = temp;
				prevL = prevL->next;
			}
		}
		else if (r == 1 && temp->next != nullptr)
		{
			afterR = temp->next;
		}
		else
		{
			if (l <= 1 && r >= 1)
			{
				if (!sublist) sublist = temp;
				else
				{
					sublist->next = temp;
					sublist = sublist->next;
				}
			}
		}
		l--; r--; temp = temp->next;
	}
	prevL->next = nullptr;
	sublist->next = nullptr;
	Node<int>* rev = reverse(sublist);
	prevL->next = rev;
	while (rev->next != nullptr)
	{
		rev = rev->next;
	}
	rev->next = afterR;
	return prevL;

}
bool palindrome(Node<int>* head)
{
	if (!head|| !head->next)
	{
		return true;
	}

	Node<int>* slow = head;
	Node<int>* fast = head;
	while (fast != nullptr && fast->next != nullptr)
	{
		
		slow = slow->next;
		fast = fast->next->next;
	}
	
	if (fast != nullptr)
	{
		slow = slow->next;
	}
	Node<int>* secHalf = reverse(slow);

	Node<int>* firHalf = head;

	// compare both halves
	while (secHalf != nullptr)
	{
		if (firHalf->data != secHalf->data)
		{
			return false;
		}
		firHalf = firHalf->next;
		secHalf = secHalf->next;
	}

	return true;

}
int count(Node<int>* nod)
{
	if (!nod)
	{
		return 0;
	}
	else
	{
		int count = 0;
		Node<int>* t = nod;
		while (t != nullptr)
		{
			count++;
			t = t->next;
		}
		return count;
	}
}
Node<int>* getIntersectionNode(Node<int>* headA, Node<int>* headB)
{
	Node<int>* res = nullptr;
	Node<int>* sec = headB;
	Node<int>* fir = headA;
	if (!headA || !headB)
	{
		return res;
	}
	int count1 = count(headA);
	int count2 = count(headB);
	if (count1 < count2)
	{
		int diff = count2 - count1;
		while (sec && diff > 0)
		{
			sec = sec->next;
			diff--;
		}
	}
	else
	{
		int diff = count1 - count2;
		while (fir && diff > 0)
		{
			fir = fir->next;
			diff--;
		}
	}
	while (fir && sec )
	{
		if (fir == sec)
		{
			res = fir;
			return res;
		}
		fir = fir->next;
		sec = sec->next;
	}
	return res;

}
Node<int>* mergeL(Node<int>* headA, Node<int>* headB)
{
	if (!headA) return headB;
	if (!headB) return headA;
	
	Node<int>* h1 = headA;
	Node<int>* h2 = headB;
	Node<int>* h = nullptr;
	Node<int>* res = nullptr;
	while (h1 != nullptr && h2 != nullptr)
	{
		if (h1->data < h2->data)
		{
			if (!res)
			{
				res = h1;
				h = res;
				h1 = h1->next;
			}
			else
			{
				res->next = h1;
				res = res->next;
				h1 = h1->next;
			}
		}
		else
		{
			if (!res)
			{
				res = h2;
				h = res;
				h2 = h2->next;
			}
			else
			{
				res->next = h2;
				res = res->next;
				h2 = h2->next;
			}
		}
	}
	if (h1) res->next = h1;
	else    res->next = h2;
	
	return h;
}
Node<int>* sortList(Node<int>* headA)
{
	if (!headA || !headA->next)
	{
		return headA;
	}
	Node<int>* slow = headA;
	Node<int>* fast = headA;
	Node<int>* prev = nullptr;
	while (fast && fast->next != nullptr)
	{
		prev = slow;
		slow = slow->next;
		fast = fast->next->next;
	}
	Node<int>* firsHalf = nullptr;
	Node<int>* secHalf = nullptr;
	if (fast != nullptr)
	{
		secHalf = slow->next;
		slow->next = nullptr;
		firsHalf = headA;
	}
	else
	{
		secHalf = slow;
		prev->next = nullptr;
		firsHalf = headA;
	}
	Node<int>* firstHalf = nullptr;
	Node<int>* secondHalf = nullptr;
	firstHalf = sortList(firsHalf);
	secondHalf = sortList(secHalf);
	return mergeL(firstHalf, secondHalf);
}

Node<int>* addTwoNumbers(Node<int>* l1, Node<int>* l2)
{
	stack<int> s1, s2;

	while (l1) {
		s1.push(l1->data);
		l1 = l1->next;
	}

	while (l2) {
		s2.push(l2->data);
		l2 = l2->next;
	}

	Node<int>* head = nullptr;
	int carry = 0;

	while (!s1.empty() || !s2.empty() || carry)
	{
		int sum = carry;

		if (!s1.empty()) {
			sum += s1.top();
			s1.pop();
		}

		if (!s2.empty()) {
			sum += s2.top();
			s2.pop();
		}

		carry = sum / 10;

		Node<int>* newNode = new Node<int>(sum % 10);
		newNode->next = head;
		head = newNode;
	}

	return head;
}
Node<int>* partition(Node<int>* head, int x)
{
	if (!head)
	{
		cout << "List is Empty\n";
		return nullptr;
	}
	Node<int>* lessHead = nullptr;
	Node<int>* lessTail = nullptr;
	Node<int>* equalHead = nullptr;
	Node<int>* equalTail = nullptr;
	Node<int>* greaterHead = nullptr;
	Node<int>* greaterTail = nullptr;
	Node<int>* curr = head;
	while (curr)
	{
		
	}
}
//1 → 2 → 4 → 5 → 1 → 2 → 3 → 5
int main()
{
	SinglyLList<int> list;
	list.insertAtHead(1);
	list.insertAtTail(4);
	list.insertAtTail(3);
	list.insertAtTail(2);
	list.insertAtTail(5);
	list.insertAtTail(2);
	list.insertAtTail(3);
	/*SinglyLList<int> list2;
	list2.insertAtTail(5);
	list2.insertAtTail(6);
	list2.insertAtTail(4);
	Node<int>* l1 = list.getHead();
	Node<int>* l2 = list2.getHead();
	Node<int>* t = addTwoNumbers(l1, l2);*/
	Node<int>* t = partition(list.getHead(),3);
	while (t != nullptr)
	{
		cout << t->data << " ";
		t = t->next;
	}
	/*Node<int>* n = list2.getHead();
	n->next->next->next = list.getHead()->next->next;
	Node<int>* r = getIntersectionNode(list.getHead(), list2.getHead());
	if (r)
	{
		cout << r->data;
	}
	else
	{
		cout << "0";
	}*/
	/*Node<int>* t = sort(list.getHead());
	while (t != nullptr)
	{
		cout << t->data;
		if (t->next != nullptr)
		{
			cout << " -> ";
		}
		t = t->next;
	}*/
	/*Node<int>* temp = list.getHead();
	Node<int>* t = rotateRight(temp, 2);
	while (t != nullptr)
	{
		cout << t->data;
		if (t->next != nullptr)
		{
			cout << " -> ";
		}
		t = t->next;
	}*/
	/*Node<string>* l = list.buildWordList("  hello     world");
	while (l != nullptr)
	{
		cout << l->data;
		l = l->next;
	}*/
	return 0;
}