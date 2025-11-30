#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void create(int arr[], int n) {
    Node *temp, *last;
    head = new Node{arr[0], NULL};
    last = head;

    for (int i = 1; i < n; i++) {
        temp = new Node{arr[i], head};
        last->next = temp;
        last = temp;
    }
}

void displayWithRepeat() {
    if (head == NULL) return;

    Node* curr = head;

    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);

    cout << head->data;
}

int main() {
    int arr[] = {20, 100, 40, 80, 60};
    int n = 5;

    create(arr, n);

    displayWithRepeat();  

    return 0;
}
