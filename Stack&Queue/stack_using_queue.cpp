#include <iostream>
#include <queue>
using namespace std;

class Stack {
private:
    queue<int> q1, q2; // Two queues to simulate stack behavior

public:
    // Push element onto the stack
    void push(int x) {
        q1.push(x);
        cout << "Pushed: " << x << endl;
    }

    // Remove the top element from the stack
    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }

        // Move all elements except the last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Pop the last element from q1 (simulating stack pop)
        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);
    }

    // Get the top element of the stack
    int top() {
        if (q1.empty()) {
            cout << "Stack is empty. Cannot retrieve top element." << endl;
            return -1;
        }

        // Move elements to q2 and get the last element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Get the top element
        int topElement = q1.front();
        cout << "Top element: " << topElement << endl;

        // Maintain the top element in q2
        q2.push(q1.front());
        q1.pop();

        // Swap q1 and q2
        swap(q1, q2);

        return topElement;
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.top(); // Should output 30
    s.pop(); // Should remove 30

    s.top(); // Should output 20
    s.pop(); // Should remove 20

    s.top(); // Should output 10
    s.pop(); // Should remove 10

    s.pop(); // Should indicate the stack is empty

    cout << "Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    return 0;
}
