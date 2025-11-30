#include <iostream>
using namespace std;

#define SIZE 5   // Maximum size of the circular queue

class CircularQueue {
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1);
    }

    // Check if queue is full
    bool isFull() {
        return ((rear + 1) % SIZE == front);
    }

    // Add element to the queue
    void enqueue(int item) {
        if (isFull()) {
            cout << "Queue Overflow! Cannot insert " << item << endl;
            return;
        }

        if (front == -1)  // First element
            front = 0;

        rear = (rear + 1) % SIZE;
        arr[rear] = item;
        cout << "Enqueued: " << item << endl;
    }

    // Remove element from the queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! No elements to delete." << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear) {
            // Only one element was present
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }

    // Display the element at the front
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Front element: " << arr[front] << endl;
    }

    // Display all elements in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear)
                break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    cout << "----- CIRCULAR QUEUE MENU -----" << endl;
    cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Check if Empty\n6. Check if Full\n7. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> value;
            q.enqueue(value);
            break;

        case 2:
            q.dequeue();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            if (q.isEmpty())
                cout << "Queue is empty." << endl;
            else
                cout << "Queue is not empty." << endl;
            break;

        case 6:
            if (q.isFull())
                cout << "Queue is full." << endl;
            else
                cout << "Queue is not full." << endl;
            break;

        case 7:
            cout << "Exiting program..." << endl;
            break;

        default:
            cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
