#include <iostream>
using namespace std;

class Stack {
    int size;
    int top;
    int *a;

public:
    Stack(int s = 100) {
        size = s;
        top = -1;
        a = new int[size];
    }

    void push(int value) {
        if (top == size - 1) {
            cout << "Stack overflow! Cannot push " << value << endl;
        } else {
            a[++top] = value;
        }
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow! Nothing to pop." << endl;
            return -1;
        }
        return a[top--];
    }

    bool isempty() {
        return (top == -1);
    }

    bool isfull() {
        return (top == size - 1);
    }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return a[top];
    }
};

int main() {
    Stack mystack(5); // small size for testing

    mystack.push(20);
    mystack.push(30);
    mystack.push(40);
    mystack.push(50);
    mystack.push(60);
    mystack.push(70); // should give overflow
    cout << "Top element: " << mystack.peek() << endl;
    cout << "Popped: " << mystack.pop() << endl;
    cout << "Popped: " << mystack.pop() << endl;
    cout << (mystack.isempty() ? "Stack is empty" : "Stack is not empty") << endl;
    cout << (mystack.isfull() ? "Stack is full" : "Stack is not full") << endl;

    return 0;
}
