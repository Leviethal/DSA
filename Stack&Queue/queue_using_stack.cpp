#include <iostream>
#include <stack>
using namespace std;

class Queue {
private:
    stack<int> s1, s2;

    // Helper function to transfer elements from s1 to s2
    void transferS1toS2() {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }

public:
    // Enqueue operation
    void enqueue(int x) {
        s1.push(x);
        cout << "Enqueued: " << x << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty. Cannot dequeue." << endl;
                return;
            }
            transferS1toS2();
        }
        cout << "Dequeued: " << s2.top() << endl;
        s2.pop();
    }

    // Front operation
    int front() {
        if (s2.empty()) {
            if (s1.empty()) {
                cout << "Queue is empty. No front element." << endl;
                return -1;
            }
            transferS1toS2();
        }
        cout << "Front element: " << s2.top() << endl;
        return s2.top();
    }

    // Check if the queue is empty
    bool empty() {
        return s1.empty() && s2.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.front(); // Should output 10
    q.dequeue(); // Should remove 10

    q.front(); // Should output 20
    q.dequeue(); // Should remove 20

    q.front(); // Should output 30
    q.dequeue(); // Should remove 30

    q.dequeue(); // Should indicate the queue is empty

    cout << "Is queue empty? " << (q.empty() ? "Yes" : "No") << endl;

    return 0;
}
