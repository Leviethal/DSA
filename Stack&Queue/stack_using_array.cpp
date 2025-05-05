#include <iostream>

using namespace std;

#define MAX 1000  // Define maximum size of stack

class Stack {
    int top; 
    int arr[MAX]; 

public:
    Stack();  
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

// Constructor
Stack::Stack() {
    top = -1;
}

// Push operation
bool Stack::push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow\n";
        return false;
    }
    arr[++top] = x;
    cout << x << " pushed into stack\n";
    return true;
}

// Pop operation
int Stack::pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return 0;
    }
    return arr[top--];
}

// Peek operation (Get top element)
int Stack::peek() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return 0;
    }
    return arr[top];
}

// Check if stack is empty
bool Stack::isEmpty() {
    return (top < 0);
}

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top element: " << s.peek() << endl;
    cout << s.pop() << " popped from stack\n";
    cout << "Top element after pop: " << s.peek() << endl;

    return 0;
}
