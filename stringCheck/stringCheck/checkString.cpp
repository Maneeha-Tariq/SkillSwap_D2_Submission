#include "String.h"
#include "Stack.h"
#include <iostream>
using namespace std;
//question 1................ a^n*b^n
bool checkString(String s)
{
	Stack<char> str;
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'a')
		{
			str.push('a');
		}
		if (s[i] == 'b')
		{
			if (s[i + 1] == 'a')
			{
				return false;
			}
			str.pop();
		}
		i++;
	}
	if (str.isEmpty())
	{
		return true;
	}
}
//question 3 ..............a^n*b^n*c^n
bool check(String s)
{
	Stack<char> str;
	int noOfA = 0, noOfC = 0, noOfB = 0;
	int i = 0;
	if (s.isEmpty())
	{
		return 1;
	}
	while (s[i] != '\0')
	{
		if (s[i] == 'a')
		{
			str.push('a');
			noOfA++;
		}
		if (s[i] == 'b')
		{
			if (s[i + 1] == 'a')
			{
				return false;
			}
			str.push('b');
			noOfB++;
		}
		if (s[i] == 'c')
		{
			if (s[i + 1] == 'a' || s[i + 1] == 'b')
			{
				return false;
			}
			str.push('c');
			noOfC++;
		}
		i++;
	}
	return (noOfA == noOfB && noOfB == noOfC);
}
// question no 4 ...........part(b)
void reverseStack(Stack<char>& s)
{
	int count = s.getNumberOfElements();
	Stack<char> t;
	
	for (int i = 0; i < count; i++)
	{
		char c = s.pop();
		for (int j = 0; j < count - i - 1; j++)
		{
			t.push(s.pop());
		}
		s.push(c);
		while (!t.isEmpty())
		{
			s.push(t.pop());
		}
		
	}
}
//question no 4 ............part(a)
void reverseWithTwoAdditional(Stack<char>& s)
{
	Stack<char> c;
	Stack<char> newC;
	while (!s.isEmpty())
	{
		char t = s.pop();
		c.push(t);
	}
	while (!c.isEmpty())
	{
		char r = c.pop();
		newC.push(r);
	}
	while (!newC.isEmpty())
	{
		char d = newC.pop();
		s.push(d);
	}
}

//Question 2.............a^s*b^t
bool checkStr(String s)
{
	if (s.isEmpty())
	{
		return 1;
	}
	int cap = s.getLength();
	int i = 0;
	while (i<cap &&s[i] == 'a')
	{
		i++;
		
	}
	while (i<cap&& s[i] == 'b')
	{
		i++;
		
	}
	return (cap == i);
}
bool isPalindrome(String& s)
{
	int cap = s.getLength();
	int i = 0, j = 0;
	Stack<char> t;
	String str(cap);

	while (i< cap && s[i] != '\0')
	{
		t.push(s[i]);
		i++;
	}
	while (!t.isEmpty())
	{
		char y = t.pop();
		str[j++] = y;
	}
	if (s.isEmpty())
	{
		return true;
	}
	if (s.compare(str) == 0)
	{
		return true;
	}
	return false;
}
void reverseWords(String& s)
{
	Stack<char> t;
	int cap = s.getLength();
	int start = 0;
	for (int i = 0; i < cap; i++)
	{
		if (s[i] != ' ')
		{
			t.push(s[i]);
		}
		else 
		{
			while(!t.isEmpty())
			{ 
				s[start++] = t.pop();
			}
			s[start++] = ' ';
		}
	}
}
// question 6..............ascending order
void putElements(Stack<char>& t)
{
	int n = t.getNumberOfElements();

	Stack<char>d;
	while (!t.isEmpty())
	{
		d.push(t.pop());
	}
	for (int i = 0; i < n; i++)
	{
		char min = d.pop();
		int count = d.getNumberOfElements();
		for (int j = 0; j < count; j++)
		{
			char s = d.pop();
			if (s < min)
			{
				d.push(min);
				min = s;
			}
			else
			{
				d.push(s);
			}
		}
		t.push(min);
	}
}
// question 7............part (a)
void transferStack(Stack<char>& s1, Stack<char>& s2)
{
	Stack<char> a;

	while (!s2.isEmpty())
	{
		s2.pop();
	}
	while (!s1.isEmpty())
	{
		char c = s1.pop();
		a.push(c);
	}
	while (!a.isEmpty())
	{
		char d = a.pop();
		s2.push(d);
	}
}
void transferWithNoAdditional(Stack<char>& s1, Stack<char>& s2)
{
	while (!s2.isEmpty())
	{
		s2.pop();
	}
	int n = s1.getNumberOfElements();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			s2.push(s1.pop());
		}
		char bottom = s1.pop();
		for (int k = 0; k < n - i - 1; k++)
		{
			s1.push(s2.pop());
		}
		s2.push(bottom);
	}
}
Stack<int> sortStack(Stack<int> r)
{
	int temp;
	Stack<int> t;

	while (!r.isEmpty())
	{
		temp = r.pop();
		while (!t.isEmpty() && temp > t.stackTop())
		{
			r.push(t.pop());
		}
		t.push(temp);

	}
	return t;
}

void storeNumberOnStack(Stack<int>& st, const String& num)
{
	int len = num.getLength();
	for (int i =0; i< len; i++)
	{
		int digit = num[i] - '0';
		st.push(digit);
	}
}
void addLargeNumbers(const String& n1, const String& n2 ,Stack<int>& num1, Stack<int>& num2, Stack<int>& result)
{
	storeNumberOnStack(num1, n1);
	storeNumberOnStack(num2, n2);
	int carry = 0;
	while (!num1.isEmpty() || !num2.isEmpty())
	{
		if (!num1.isEmpty()&& !num2.isEmpty())
		{
			carry += num1.pop()+num2.pop();
			if (carry >= 0 && carry <= 9)
			{
				result.push(carry);
				carry = 0;
			}
			else if (carry > 9)
			{
				int unitPart = carry % 10;
				int carryPart = carry / 10;
				result.push(unitPart);
				carry += carryPart;
			}

		}
	}
	if (!num1.isEmpty())
	{
		while (!num1.isEmpty())
		{
			if (carry)
			{
				result.push(num1.pop() + carry);
			}
			else
			{
				result.push(num1.pop());
			}
		}
	}
	else if (!num2.isEmpty())
	{
		while (!num2.isEmpty())
		{
			if (carry)
			{
				result.push(num2.pop() + carry);
			}
			else
			{
				result.push(num2.pop());
			}
		}
	}
	while (!result.isEmpty())
	{
		cout << result.pop();
	}
}
int precedence(char op)
{
	if (op == '(' || op == ')') return 0;
	if (op == '+' || op == '-')  return 1;
	if (op == '*' || op == '/'||op=='%') return 2;
	if (op == '^') return 3;
	return 0;
}
bool isOperator(char ch)
{
	return (ch == '+' || ch == '-' || ch == '/' || ch == '*'|| ch=='^');
}
bool isOperand(char c)
{
	return (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z');
}
String infixToPostfix(String& infix)
{
	Stack<char> s;
	int len = infix.getLength();
	String postfix=" ";
	int i = 0;
	while (i< len)
	{
		char c = infix[i];
		if (isOperand(c))
		{
			postfix+= c;
		}
		else if (c == '(')
		{
			s.push(c);
		}
		else if (c == ')')
		{
			while (!s.isEmpty() && s.stackTop() != '(')
			{
				postfix+= s.stackTop();
				s.pop();
			}
			if (!s.isEmpty() && s.stackTop() == '(')
			{
				s.pop();
			}
		}
		else if (isOperator(c))
		{
			while (!s.isEmpty() &&((precedence(s.stackTop()) > precedence(c)) ||(precedence(s.stackTop()) == precedence(c) && c != '^')))
			{
				postfix+= s.stackTop();
				s.pop();
			}
			
			s.push(c);
			
		}
		i++;
	}
	while (!s.isEmpty())
	{
		postfix+= s.stackTop();
		s.pop();
	}
	postfix+=  '\0';
	return postfix;

}
//with two stacks
//String infixToPrefix(String& infix)
//{
//	Stack<char> operatorStack;
//	Stack<String> operandStack;
//	int len = infix.getLength();
//
//	for (int i = len - 1; i >= 0; i--)   // right-to-left traversal
//	{
//		char ch = infix[i];
//
//		// agar operand mila (A-Z, a-z, 0-9)
//		if (isOperand(ch))
//		{
//			String temp = "";   // empty String
//			temp += ch;         // ek char ko String me dalna
//			operandStack.push(temp);
//		}
//
//		// ')' treat as opening
//		else if (ch == ')')
//		{
//			operatorStack.push(ch);
//		}
//
//		// '(' treat as closing
//		else if (ch == '(')
//		{
//			while (!operatorStack.isEmpty() && operatorStack.stackTop() != ')')
//			{
//				// pop 2 operands
//				String op1 = operandStack.stackTop(); operandStack.pop();
//				String op2 = operandStack.stackTop(); operandStack.pop();
//
//				char op = operatorStack.stackTop(); operatorStack.pop();
//
//				// prefix = operator + op1 + op2
//				String expr = "";
//				expr += op;
//				expr += op1;
//				expr += op2;
//
//				operandStack.push(expr);
//			}
//			if (!operatorStack.isEmpty()) operatorStack.pop(); // remove ')'
//		}
//
//		// agar operator mila
//		else if (isOperator(ch))
//		{
//			while (!operatorStack.isEmpty() &&
//				precedence(operatorStack.stackTop()) > precedence(ch))
//			{
//				String op1 = operandStack.stackTop(); operandStack.pop();
//				String op2 = operandStack.stackTop(); operandStack.pop();
//				char op = operatorStack.stackTop(); operatorStack.pop();
//
//				String expr = "";
//				expr += op;
//				expr += op1;
//				expr += op2;
//
//				operandStack.push(expr);
//			}
//			operatorStack.push(ch);
//		}
//	}
//
//	// remaining operators
//	while (!operatorStack.isEmpty())
//	{
//		String op1 = operandStack.stackTop(); operandStack.pop();
//		String op2 = operandStack.stackTop(); operandStack.pop();
//		char op = operatorStack.stackTop(); operatorStack.pop();
//
//		String expr = "";
//		expr += op;
//		expr += op1;
//		expr += op2;
//
//		operandStack.push(expr);
//	}
//
//	return operandStack.stackTop();
//}
//with one stack
String infixToPrefix1Stk(String& infix)
{
	Stack<char> s;
	int len = infix.getLength();
	String prefix = "";

	// Traverse from right to left
	for (int i = len - 1; i >= 0; i--)
	{
		char c = infix[i];

		if (isOperand(c))
		{
			// prepend operand to result
			prefix += c;
		}
		else if (c == ')')
		{
			s.push(c);
		}
		else if (c == '(')
		{
			while (!s.isEmpty() && s.stackTop() != ')')
			{
				prefix += s.stackTop();
				s.pop();
			}
			if (!s.isEmpty() && s.stackTop() == ')')
				s.pop();
		}
		else if (isOperator(c))
		{
			while (!s.isEmpty() &&
				(precedence(s.stackTop()) > precedence(c) ||
					(precedence(s.stackTop()) == precedence(c) && c == '^')))
			{
				prefix += s.stackTop();
				s.pop();
			}
			s.push(c);
		}
	}

	// pop remaining operators
	while (!s.isEmpty())
	{
		prefix += s.stackTop();
		s.pop();
	}
	prefix.reverse();
	return prefix;
}
#include <iostream>
#include <stack>
using namespace std;

stack<int> mainStack;   // normal stack
stack<int> minStack;    // minimums track karega

// Push function
void push(int x) {
	mainStack.push(x);

	// Agar minStack empty hai ya x <= current minimum
	if (minStack.empty() || x <= minStack.top()) {
		minStack.push(x);
	}
}

// Pop function
void pop() {
	if (mainStack.empty()) {
		cout << "Stack Underflow!" << endl;
		return;
	}
	int val = mainStack.top();
	mainStack.pop();

	if (val == minStack.top()) {
		minStack.pop();
	}
}

// Get Minimum in O(1)
int getMin() {
	if (minStack.empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	}
	return minStack.top();
}

// Top element
int top() {
	if (mainStack.empty()) {
		cout << "Stack is empty!" << endl;
		return -1;
	}
	return mainStack.top();
}
#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
	stack<int> s;        // normal stack
	stack<int> maxStack; // stores maximums

public:
	void push(int x) {
		s.push(x);
		if (maxStack.empty() || x >= maxStack.top())
			maxStack.push(x);
	}

	void pop() {
		if (s.empty()) return;
		int topVal = s.top();
		s.pop();
		if (topVal == maxStack.top())
			maxStack.pop();
	}

	int getMax() {
		if (maxStack.empty()) return -1; // or throw error
		return maxStack.top();
	}
};
double resultOfPostfix(const String& post)
{
	String postfix{ post };
	long long int result = 0;
	Stack<String> operandss;
	int i = 0;
	String c;
	while (postfix)
	{
		if (postfix[i] != '+' && postfix[i] != '-' && postfix[i] != '*' && postfix[i] != '/' && postfix[i] != '%')
		{
			c = postfix(",");
			operandss.push(c);
		}
		else
		{
			c = postfix(",");

			String s2 = operandss.pop();
			String  s1{ operandss.pop() };

			int operand2 = (long long int)s2;
			int operand1 = (long long int)s1;
			if ((c == "+") == 0)
				result = operand1 + operand2;
			else if ((c == '-') == 0)
				result = operand1 - operand2;
			else if ((c == '*') == 0)
				result = operand1 * operand2;
			else if ((c == '/') == 0)
				result = operand1 / operand2;
			else if ((c == '%') == 0)
				result = operand1 % operand2;
			String y;
			y = result;
			operandss.push(y);

		}
	}
	result = (long long int)operandss.pop();

	return result;
}
//float resultPostfix( String postfix)
//{
//	float ans = 0;
//	Stack<float>stk;
//	String temp;
//	char* ptr;
//	while (!postfix.isEmpty())
//	{
//		temp = postfix(",");
//		if (temp.getLength() == 1)
//		{
//			ptr = &temp[0];
//			if (isOperator(temp[0]))
//			{
//				float op1, op2;
//				if (!stk.isEmpty())
//				{
//					op2 = stk.pop();
//				}
//				if (!stk.isEmpty())
//				{
//					op1 = stk.pop();
//				}
//				ans = evaluate(op1, op2, temp[0]);
//				stk.push(ans);
//			}
//			else
//			{
//				stk.push(temp.convertToFloat());
//			}
//		}
//		else
//		{
//			stk.push(temp.convertToFloat());
//		}
//		return stk.pop();
//	}
//{













#include <initializer_list>

template <typename T>
class Array
{
	T* data;
	int size;
	bool isValidIndex(int index) const
	{
		return (index >= 0 && index < size);

	}
public:
	Array()
	{
		data = nullptr;
		size = 0;
	}
	Array(int s) :Array()
	{
		if (s > 0)
		{
			data = new T[s];
			size = s;
		}
	}
	Array(const Array& r) :Array()
	{
		if (r.size <= 0)
			return;
		size = r.size;
		data = new T[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = r.data[i];
		}
	}
	Array<T>& operator=(const Array<T>& r)
	{
		if (r.size == 0)
		{
			this->~Array();
			return *this;
		}
		if (this == &r)
			return *this;
		this->~Array();
		size = r.size;
		data = new T[size];
		int i;
		for (i = 0; i < size; i++)
		{
			data[i] = r.data[i];
		}
		return *this;
	}
	Array(Array<T>&& other) :Array()
	{
		data = other.data;
		size = other.size;
		other.data = nullptr;
		other.size = 0;
	}
	Array<T>& operator=(Array<T>&& other)
	{
		if (this == &other)
		{
			return *this;
		}
		delete[] data;

		data = other.data;
		size = other.size;

		other.data = nullptr;
		other.size = 0;

		return *this;
	}
	const T& operator [](int index) const
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			cout << "Index out of bound";
			exit(0);
		}
	}
	T& operator [](int index)
	{
		if (isValidIndex(index))
		{
			return data[index];
		}
		else
		{
			cout << "Index out of bound";
			exit(0);
		}
	}
	int getSize() const
	{
		return size;
	}
	void reSize(int s)
	{
		if (s <= 0)
		{
			this->~Array();
			return;
		}
		T* temp = new T[s];
		int i = 0;
		while (i < size && i < s)
		{
			temp[i] = data[i];
			i++;
		}
		this->~Array();
		data = temp;
		size = s;
	}
	~Array()
	{
		if (data)
		{
			delete[]data;
			data = nullptr;
		}
		size = 0;
	}
	Array(initializer_list<T> val) :Array()
	{
		size = val.size();
		if (size == 0)
			return;
		data = new T[size];
		int i = 0;
		for (auto x : val)
		{
			data[i] = x;
			i++;
		}
	}
	const T* begin()
	{
		return &data[0];
	}
	const T* end()
	{
		return &data[size];
	}
};
template <typename T>
ostream& operator <<(ostream& out, const Array<T>& r)
{
	out << "{";
	for (int i = 0; i < r.getSize(); i++)
	{
		out << r[i];
		if (i < r.getSize() - 1)
		{
			out << " , ";
		}
	}
	out << "}";
	return out;
}
template <typename T>
istream& operator >>(istream& out, Array<T>& r)
{
	for (int i = 0; i < r.getSize(); i++)
	{
		out >> r[i];
	}
	return out;
}

bool reflectionOfEachOther(Stack<int>&a, Stack<int>&b)
{
	Stack<int> temp;
	bool isReflection = true;
	while (!a.isEmpty())
	{
		temp.push(a.pop());
	}
	while (!b.isEmpty())
	{
		a.push(b.pop());
	}
	while (!temp.isEmpty())
	{
		b.push(temp.pop());
	}
	while (!b.isEmpty())
	{
		int get = a.pop();
		if (get != b.stackTop())
		{
			isReflection = false;
		}
		temp.push(get);
		temp.push(b.pop());
	}
	while (!temp.isEmpty())
	{
		b.push(temp.pop());
		a.push(temp.pop());
	}
	while (!b.isEmpty())
    {
	   temp.push(b.pop());
    }

	while (!a.isEmpty())
	{
		b.push(a.pop());
	}
    while (!temp.isEmpty())
    {
	  a.push(temp.pop());
    }
	return check;
	
}

int main()
{
	Stack<int>a;
	a.push(-1);
	a.push(2);
	a.push(4);
	a.push(5);
	Stack<int> b;
	b.push(9);
	b.push(4);
	b.push(2);
	b.push(-1);
	cout << "Before calling function: stack<int> a: ";
	a.display();
	cout << "\nBefore calling function: stack<int> b: ";
	b.display();
	cout<< "\n"<< reflectionOfEachOther(a , b);
	cout << "\nAfter calling function: stack<int> a: ";
	a.display();
	cout << "\nAfter calling function: stack<int> b: ";
	b.display();
	/*String t= "()((())";*/
	/*cout<< lengthOfPossibleBrackets(t);*/

}
/*Stack<char> u;
	a.push('1');
	a.push('2');
	a.push('3');
	a.push('4');
	a.push('5');
	Stack<char>b;*/
	/*a.display();
	cout << endl;*/
	/*transferWithNoAdditional(a,b);
	b.display();*/
	/*a.display();
	cout << endl;*/
	/*Stack<char> str;
	str.push('g');
	str.push('h');
	str.push('i');
	transferStack(a, str);
	str.display();*/
	/*String a = "A+B*C-D+E/F/(G+H)";
	String t= infixToPrefix1Stk(a);
	cout << t;*/
	/*String s = "1.34,2.66,+,2,/,10,+";
	cout << resultOfPostfix(s);*/
	/*Stack<int> s;
	s.push(4);
	s.push(6);
	s.push(3);
	s.push(1);

	Stack<int> sorted = sortStack(s);
	while (!sorted.isEmpty())
	{
		cout << sorted.pop() << " ";
	}*/

	//push(5);
	//push(2);
	//push(8);
	//push(1);
	//push(3);

	//cout << "Current Min = " << getMin() << endl;  // 1
	//pop(); // remove 3
	//pop(); // remove 1
	//cout << "Current Min = " << getMin() << endl;  // 2
 //
	//MaxStack ms;
	//ms.push(5);
	//ms.push(2);
	//ms.push(9);
	//ms.push(7);
	//ms.push(1);

	//cout << "Current Max: " << ms.getMax() << endl; // 9
	//ms.pop(); // pop 1
	//ms.pop(); // pop 7
	//cout << "Current Max: " << ms.getMax() << endl; // 9
	//ms.pop(); // pop 9
	//cout << "Current Max: " << ms.getMax() << endl; // 5


