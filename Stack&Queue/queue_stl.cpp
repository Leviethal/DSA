#include <iostream>
#include <queue> // Required for std::queue
using namespace std;
int main() {
    queue<int> q; // Create an integer queue

    // Enqueue elements
    q.push(10);
    q.push(20);
    q.push(30);

    cout << "Front element: " << q.front() << endl; // 10
    cout << "Rear element: " << q.back() << endl;   // 30

    // Dequeue an element
    q.pop(); // Removes 10

    cout << "Front element after dequeue: " << q.front() << endl; // 20
    cout << "Queue size: " << q.size() << endl; // 2

    // Check if queue is empty
    if (q.empty()) {
        cout << "Queue is empty!" << endl;
    } else {
        cout << "Queue is not empty!" << endl;
    }

    // Display all elements in the queue
    cout << "Queue elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
