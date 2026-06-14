//bool checkLanguage(const String s, int n)
//{
//	Stack<char> stack;
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		stack.push(s[i]);
//	}
//	int index = 0;
//	int index1 = 0;
//	for (int i = 0; i < n && !stack.isEmpty(); i++) {
//		char val = stack.pop();
//		if (val == 'b')
//		{
//
//			index++;
//		}
//	}
//	while (!stack.isEmpty())
//	{
//		char val = stack.pop();
//		if (val == 'a')
//		{
//
//			index1++;
//		}
//	}
//	return (index == n && index1 == n);
//
//}
//bool checkLanguage(const String s, int n, int t)
//{
//	Stack<char> stack;
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		stack.push(s[i]);
//	}
//	int index = 0;
//	int index1 = 0;
//	for (int i = 0; i < t && !stack.isEmpty(); i++) {
//		char val = stack.pop();
//		if (val == 'b')
//		{
//
//			index++;
//		}
//	}
//	while (!stack.isEmpty())
//	{
//		char val = stack.pop();
//		if (val == 'a')
//		{
//
//			index1++;
//		}
//	}
//	return (index == t && index1 == n);
//
//}
//bool checkLanguage3(const String s, int n)
//{
//	Stack<char> stack;
//	for (int i = 0; s[i] != '\0'; i++)
//	{
//		stack.push(s[i]);
//	}
//	int aCount = 0;
//	int bCount = 0;
//	int cCount = 0;
//	for (int i = 0; i < n && !stack.isEmpty(); i++) {
//		char val = stack.pop();
//		if (val == 'c')
//		{
//
//			cCount++;
//		}
//	}
//	for (int i = 0; i < n && !stack.isEmpty(); i++) {
//		char val = stack.pop();
//		if (val == 'b')
//		{
//
//			bCount++;
//		}
//	}
//	while (!stack.isEmpty())
//	{
//		char val = stack.pop();
//		if (val == 'a')
//		{
//
//			aCount++;
//		}
//	}
//	return (aCount == n && bCount == n && cCount == n);
//
//}
//void reverseOrderElement(Stack<int>& s)
//{
//	//Stack<int> temp1;
//	//Stack <int>temp2;
//	//while (!s.isEmpty())
//	//{
//	//	int val = s.pop();
//	//	cout  << val;
//	//	temp1.push(val);
//	//}
//	//while (!temp1.isEmpty())
//	//{
//	//	int val = temp1.pop();
//	//	temp2.push(val);
//	//}
//	//while (!temp2.isEmpty())
//	//{
//	//	int val = temp2.pop();
//	//	s.push(val);
//	//}
//	Stack<int> temp;
//	int x;
//
//	int n = s.getNumberOfElements();
//
//	for (int i = 0; i < n; i++)
//	{
//
//		x = s.pop();
//
//
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			temp.push(s.pop());
//		}
//
//
//		s.push(x);
//
//
//		while (!temp.isEmpty())
//		{
//			s.push(temp.pop());
//		}
//	}
//}
//void reverseOrderElementWithVar(Stack<int>& s)
//{
//	Stack <int> temp;
//	int val = 0;
//	while (!s.isEmpty())
//	{
//		val = s.pop();
//		if (temp.isEmpty())
//		{
//			temp.push(val);
//		}
//		else
//		{
//			while (!temp.isEmpty() && val > temp.stackTop())
//			{
//				s.push(temp.pop());
//			}
//			temp.push(val);
//		}
//	}
//	while (!temp.isEmpty())
//	{
//		s.push(temp.pop());
//	}
//}
//bool IsHomogenousBracketValid(String s)
//{
//	Stack<char> temp;
//	int index = 0;
//	while (s[index] != '\0')
//	{
//		int val = s[index];
//
//		if (val == '(')
//		{
//			temp.push(s[index]);
//		}
//		if (val == ')')
//		{
//			if (temp.isEmpty())
//				return false;
//			temp.pop();
//		}
//		index++;
//	}
//	if (temp.isEmpty())
//	{
//		return true;
//	}
//
//	return false;
//
//}
//bool IsHeterogenousBracketValid(String s)
//{
//	Stack<char> temp;
//	int index = 0;
//	while (s[index] != '\0')
//	{
//		char val = s[index];
//
//		if (val == '(' || val == '{' || val == '[')
//		{
//			temp.push(s[index]);
//		}
//		if (val == ')' || val == '}' || val == ']')
//		{
//			if (temp.isEmpty())
//				return false;
//			char top = temp.pop();
//			if ((val == ')' && top != '(') ||
//				(val == '}' && top != '{') ||
//				(val == ']' && top != '['))
//			{
//				return false;
//			}
//		}
//		index++;
//	}
//	if (temp.isEmpty())
//	{
//		return true;
//	}
//
//	return false;
//
//}





//Task 2:
//#include <iostream>
//#include "String.h"
//#include "Stack.h"
//
//using namespace std;
//
//double solvePostfix(String& postfix)
//{
//    cout << "function called\n";
//    int i = 0;
//    Stack<char> operatorStack;
//    Stack<double> operandStack;
//
//    while (postfix[i] != '\0')
//    {
//        if (postfix[i] == ',')
//        {
//            i++;
//        }
//        else
//        {
//            char ch = postfix[i];
//            cout << "character: " << ch << "\n";
//
//            if (ch == '*' || ch == '/' || ch == '%' || ch == '+' || ch == '-')
//            {
//                operatorStack.push(ch);
//                i++;
//            }
//            else
//            {
//                // Parse number (integer or decimal)
//                double operand = 0.0;
//                bool isDecimal = false;
//                double decimalPlace = 10.0;
//
//                while ((postfix[i] >= '0' && postfix[i] <= '9') || postfix[i] == '.')
//                {
//                    if (postfix[i] == '.')
//                    {
//                        isDecimal = true;
//                        i++;
//                    }
//                    else
//                    {
//                        if (!isDecimal)
//                        {
//                            // Integer part
//                            operand = operand * 10 + (postfix[i] - '0');
//                        }
//                        else
//                        {
//                            // Decimal part  
//                            operand = operand + (postfix[i] - '0') / decimalPlace;
//                            decimalPlace *= 10.0;
//                        }
//                        i++;
//                    }
//                }
//                cout << "operand: " << operand << "\n";
//                operandStack.push(operand);
//            }
//        }
//    }
//
//    // Reverse stacks for correct order
//    Stack<char> operatorStack2;
//    Stack<double> operandStack2;
//    while (!operatorStack.isEmpty())
//    {
//        operatorStack2.push(operatorStack.pop());
//    }
//    while (!operandStack.isEmpty())
//    {
//        operandStack2.push(operandStack.pop());
//    }
//
//    double oprnd1 = 0, oprnd2 = 0;
//    double res = 0.0;
//    char op;
//
//    oprnd1 = operandStack2.pop();
//    cout << "First operand: " << oprnd1 << endl;
//
//    while (!operandStack2.isEmpty())
//    {
//        oprnd2 = operandStack2.pop();
//        op = operatorStack2.pop();
//        cout << "Second operand: " << oprnd2 << ", Operator: " << op << endl;
//
//        if (op == '+') res = oprnd1 + oprnd2;
//        else if (op == '-') res = oprnd1 - oprnd2;
//        else if (op == '*') res = oprnd1 * oprnd2;
//        else if (op == '/') res = oprnd1 / oprnd2;
//
//        cout << "Result: " << res << endl;
//        oprnd1 = res;
//    }
//    return res;
//}
//
//int main()
//{
//    String postfix("1.34,2.66,+,2,/,10,+");
//    cout << solvePostfix(postfix);
//}