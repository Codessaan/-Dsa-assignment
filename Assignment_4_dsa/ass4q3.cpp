#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    if (q.empty() || q.size() % 2 != 0) {
        cout << "Queue must have even number of elements!" << endl;
        return;
    }

    int halfSize = q.size() / 2;
    stack<int> s;

    // Step 1: Push first half into stack (reverses order)
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue back stack elements to queue (so first half reversed goes to back)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Move first half (reversed second half) to the back
    for (int i = 0; i < halfSize; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Again push first half into stack
    for (int i = 0; i < halfSize; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 5: Interleave elements of stack (first half) and queue (second half)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, value;

    cout << "Enter number of elements (even number): ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even number of elements!" << endl;
        return 0;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        q.push(value);
    }

    cout << "\nOriginal Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    interleaveQueue(q);

    cout << "Interleaved Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
