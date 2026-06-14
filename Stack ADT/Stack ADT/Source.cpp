#include <iostream>
#include "Stack.h"
#include "String.h"
using namespace std;

int length_Of_Valid_brackets(String& s)
{
    Stack<char> left, right;
    int i = 0, pairs = 0;

    int len = s.getLength(); 
    for(int i=0;i<len;i++)
    {
        if (s[i] == '(')
        {
            left.push('(');
        }
        else if (s[i] == ')')
        {
            if (!left.isEmpty())
            {
                left.pop();
                pairs++;
            }
            else
            {
                right.push(')');
            }
        }
        
    }
    return pairs * 2;
}

int main()
{
    Stack<int> s;
    s.push(80);
    s.push(20);
    s.push(30);

    cout << "Stack elements: ";
    s.display();
    cout << endl;

    String t = "((((())))";
    cout << length_Of_Valid_brackets(t);

    return 0;
}
