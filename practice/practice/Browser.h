#ifndef BROWSER_H
#define BROWSER_H

#include <iostream>
#include "String.h"
#include "Stack.h"   // your Stack class
using namespace std;

class Browser
{
    Stack<String> backStack;
    Stack<String> forwardStack;
    String currentPage;
    int historyLimit; // for manual limit handling

    void trimBackHistoryIfNeeded()
    {
        // If backStack exceeds historyLimit, remove the oldest (bottom element)
        // Your stack has no direct remove-bottom, so we'll do a trick:
        if (backStack.getNumberOfElements() > historyLimit)
        {
            Stack<String> temp;
            int total = backStack.getNumberOfElements();

            // Pop everything into temp
            for (int i = 0; i < total; i++)
            {
                temp.push(backStack.pop());
            }

            // Remove the last element (which was the oldest)
            temp.pop();

            // Push back to backStack (restoring order)
            Stack<String> temp2;
            while (!temp.isEmpty())
            {
                temp2.push(temp.pop());
            }
            while (!temp2.isEmpty())
            {
                backStack.push(temp2.pop());
            }
        }
    }

public:
    Browser(int limit = 5)
    {
        historyLimit = limit;
        currentPage = "Home";
    }

    void visitPage(const String& url)
    {
        backStack.push(currentPage);
        trimBackHistoryIfNeeded();  // maintain fixed history size
        currentPage = url;

        // visiting a new page clears forward stack
        while (!forwardStack.isEmpty())
        {
            forwardStack.pop();
        }

        cout << "🌐 Visiting: " << currentPage << endl;
    }

    void goBack()
    {
        if (backStack.isEmpty())
        {
            cout << "🚫 No back history.\n";
            return;
        }
        forwardStack.push(currentPage);
        currentPage = backStack.pop();
        cout << "⬅️  Went Back to: " << currentPage << endl;
    }

    void goForward()
    {
        if (forwardStack.isEmpty())
        {
            cout << "🚫 No forward history.\n";
            return;
        }
        backStack.push(currentPage);
        currentPage = forwardStack.pop();
        cout << "➡️  Went Forward to: " << currentPage << endl;
    }

    void showHistory()
    {
        cout << "\n--- Browser History ---\n";
        cout << "Back Stack: ";
        backStack.display();
        cout << "\nCurrent Page: " << currentPage;
        cout << "\nForward Stack: ";
        forwardStack.display();
        cout << "\n-----------------------\n";
    }
};

#endif

