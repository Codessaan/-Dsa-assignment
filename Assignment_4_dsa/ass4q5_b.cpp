#include <iostream>
#include <queue>
using namespace std;

class StackUsingOneQueue {
    queue<int> q;

public:
    void push(int x) {
        int size = q.size();
        q.push(x); // Add new element

        // Rotate elements behind the new one
        for (int i = 0; i < size; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    void pop() {
        if (q.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    int top() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q.front();
    }

    bool isEmpty() {
        return q.empty();
    }

    void display() {
        if (q.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingOneQueue s;
    int choice, val;

    cout << "----- STACK USING ONE QUEUE -----" << endl;
    cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";

    do {
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> val;
            s.push(val);
            break;

        case 2:
            s.pop();
            break;

        case 3:
            cout << "Top element: " << s.top() << endl;
            break;

        case 4:
            s.display();
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 5);

    return 0;
}
