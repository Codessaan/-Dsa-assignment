#include <iostream>
#include <queue>
using namespace std;

class StackUsingTwoQueues {
    queue<int> q1, q2;

public:
    void push(int x) {
        // Step 1: Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Step 2: Push new element into q1
        q1.push(x);

        // Step 3: Move everything back from q2 to q1
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << "Popped: " << q1.front() << endl;
        q1.pop();
    }

    int top() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return q1.front();
    }

    bool isEmpty() {
        return q1.empty();
    }

    void display() {
        if (q1.empty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        queue<int> temp = q1;
        cout << "Stack elements (top to bottom): ";
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues s;
    int choice, val;

    cout << "----- STACK USING TWO QUEUES -----" << endl;
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