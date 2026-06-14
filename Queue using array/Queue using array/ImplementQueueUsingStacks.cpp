#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class MyQueue
{
    stack<int>input;
    stack<int>output;

public:

    MyQueue()
    {

    }

    void push(int x) 
    {
        input.push(x);
    }

    int pop() 
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        int element = output.top();
        output.pop();
        return element;
    }
    int peek() 
    {
        if (output.empty())
        {
            while (!input.empty())
            {
                output.push(input.top());
                input.pop();
            }
        }
        return output.top();
    }

    bool empty()
    {
        return input.empty()&& output.empty() ? 1 : 0;
    }
};
//using two queues
class MyStack
{
    queue<int>q1;
    queue<int>q2;

public:

    MyStack()
    {

    }
    void push(int x)
    {
        if (!q1.empty())
        {
            q1.push(x);
        }
        else if (!q2.empty())
        {
            q2.push(x);
        }
        else if(q1.empty() && q2.empty())
        {
            q1.push(x);
        }
    }
    int pop()
    {
        int element;
        if (!q1.empty())
        {
            int n = q1.size();
            for (int i = 0; i < n - 1; i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            element = q1.front();
            q1.pop();
        }
        else if (!q2.empty())
        {
            int n = q2.size();
            for (int i = 0; i < n - 1; i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            element = q2.front();
            q2.pop();
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
        return element;
    }
    int top()
    {
       
        if (!q1.empty())
        {
            return q1.back();
        }
        else if (!q2.empty())
        {
            return q2.back();
        }
        else if (empty())
        {
            cout << "Stack is empty";
            return -1;
        }
        
    }
    bool empty()
    {
        return q1.empty() && q2.empty() ? 1 : 0;
    }

};
// using one queue
class Stack
{
    queue<int>q;
public:
    Stack()
    {

    }
    void push(int x)
    {
        q.push(x);
    }
    int pop()
    {
        if (!q.empty())
        {
            for (int i = 0; i < q.size() - 1; i++)
            {
                int temp = q.front();
                q.pop();
                q.push(temp);
            }
            int element = q.front();
            q.pop();
            return element;
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
        
    }
    int top()
    {
        if (!q.empty())
        {
            return q.back();
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
    }
    bool empty()
    {
        return q.empty() ? 1 : 0;
    }
};
int main()
{
    MyQueue* myQueue = new MyQueue();
    myQueue->push(1);
    myQueue->push(2);
    int param_3 = myQueue->peek();
    if (param_3 != -1)
    {
        cout << "Peek Element: " << param_3 << "\n";
    }
    int param_2 = myQueue->pop();
    cout << "Popped Element: " << param_2 << "\n";
    bool param_4 = myQueue->empty();
    if (param_4)
    {
        cout << "Queue is Empty";
    }
    else
    {
        cout << "Queue is not Empty";
    }



}




/*int element;
        if (!q1.empty())
        {
            int n = q1.size();
            for (int i = 0; i < n - 1; i++)
            {
                q2.push(q1.front());
                q1.pop();
            }
            element = q1.front();
            q2.push(q1.front());
            q1.pop();
        }
        else if (!q2.empty())
        {
            int n = q2.size();
            for (int i = 0; i < n - 1; i++)
            {
                q1.push(q2.front());
                q2.pop();
            }
            element = q2.front();
            q1.push(q2.front());
            q2.pop();
        }
        else
        {
            cout << "Stack is Empty";
            return -1;
        }
        return element;*/