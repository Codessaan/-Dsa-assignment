#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

bool isCircular(Node* head) {
    if (head == NULL) 
        return false;

    Node* temp = head->next;

    while (temp != NULL && temp != head) {
        temp = temp->next;
    }

    return (temp == head);
}

int main() {
    
    Node* n1 = new Node{2, NULL};
    Node* n2 = new Node{4, NULL};
    Node* n3 = new Node{6, NULL};
    Node* n4 = new Node{7, NULL};
    Node* n5 = new Node{5, NULL};

    head = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;

    n5->next = n1;

    if (isCircular(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
