#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[parent] < heap[index]) {
                swap(heap[parent], heap[index]);
                index = parent;
            } else {
                break;
            }
        }
    }

    void heapifyDown(int index) {
        int n = heap.size();
        while (true) {
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;

            if (left < n && heap[left] > heap[largest])
                largest = left;
            if (right < n && heap[right] > heap[largest])
                largest = right;

            if (largest != index) {
                swap(heap[index], heap[largest]);
                index = largest;
            } else {
                break;
            }
        }
    }

public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size() - 1);
    }

    void pop() {
        if (heap.empty()) {
            cout << "Priority Queue is empty!\n";
            return;
        }
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
    }

    int top() {
        if (!heap.empty())
            return heap[0];
        cout << "Priority Queue is empty!\n";
        return -1;
    }

    bool empty() {
        return heap.empty();
    }

    void display() {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Priority Queue elements: ";
    pq.display();

    cout << "Top element (highest priority): " << pq.top() << endl;

    pq.pop();
    cout << "After extracting max, Priority Queue elements: ";
    pq.display();

    return 0;
}
