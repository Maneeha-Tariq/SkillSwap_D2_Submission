#include <iostream>
using namespace std;

// ================= NODE =================
struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// ================= STACK =================
class Stack {
    Node* top;

public:

    // Constructor
    Stack() {
        top = nullptr;
    }

    // ================= PUSH =================
    void push(int value) {

        Node* newNode = new Node(value);

        newNode->next = top;

        top = newNode;

        cout << value << " pushed into stack\n";
    }

    // ================= POP =================
    void pop() {

        if (top == nullptr) {
            cout << "Stack Underflow\n";
            return;
        }

        Node* temp = top;

        cout << temp->data << " popped\n";

        top = top->next;

        delete temp;
    }

    // ================= PEEK =================
    void peek() {

        if (top == nullptr) {
            cout << "Stack is Empty\n";
            return;
        }

        cout << "Top Element: " << top->data << endl;
    }

    // ================= DISPLAY =================
    void display() {

        if (top == nullptr) {
            cout << "Stack Empty\n";
            return;
        }

        Node* temp = top;

        cout << "Stack:\n";

        while (temp != nullptr) {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

    // ================= ISEMPTY =================
    bool isEmpty() {
        return top == nullptr;
    }

    // Destructor
    ~Stack() {
        while (top != nullptr) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main()
{

    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.peek();

    s.pop();

    s.display();

    return 0;
}