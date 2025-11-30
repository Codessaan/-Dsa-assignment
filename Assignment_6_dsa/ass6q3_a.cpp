#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void create(int arr[], int n) {
    Node *temp, *last;
    head = new Node{arr[0], NULL, NULL};
    last = head;
    
    for (int i = 1; i < n; i++) {
        temp = new Node{arr[i], last, NULL};
        last->next = temp;
        last = temp;
    }
}

int sizeDLL() {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int arr[] = {10, 20, 30, 40};
    create(arr, 4);

    cout << "Size of Doubly Linked List = " << sizeDLL();
    return 0;
}
