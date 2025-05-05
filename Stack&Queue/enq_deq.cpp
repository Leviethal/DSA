#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    // Constructor to initialize the queue
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Destructor to free memory
    ~Queue() {
        delete[] arr;
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1 || front > rear;
    }

    // Check if the queue is full
    bool isFull() {
        return rear == size - 1;
    }

    // Add an element to the queue (Enqueue)
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full. Cannot enqueue " << value << endl;
            return;
        }
        if (isEmpty()) {
            front = 0; // Set front to 0 on first enqueue
        }
        arr[++rear] = value;
        cout << "Enqueued: " << value << endl;
    }

    // Remove an element from the queue (Dequeue)
    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }
        int value = arr[front++];
        cout << "Dequeued: " << value << endl;
        return value;
    }

    // Peek at the front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty. Nothing to peek." << endl;
            return -1;
        }
        return arr[front];
    }

    // Get the size of the queue
    int getSize() {
        if (isEmpty()) return 0;
        return rear - front + 1;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Queue q(5); // Create a queue with a capacity of 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Should show queue is full
    q.display();

    cout << "Front element: " << q.peek() << endl;
    cout << "Queue size: " << q.getSize() << endl;

    return 0;
}
