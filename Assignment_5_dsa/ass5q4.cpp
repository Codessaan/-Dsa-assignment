#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end
void insertAtEnd(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = newNode;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << "->NULL" << endl;
}

// Function to reverse the linked list
void reverseList(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;    // Store next node
        current->next = prev;    // Reverse current node's pointer
        prev = current;          // Move prev forward
        current = next;          // Move current forward
    }

    head = prev; // Update head to new first node
}

// Main function
int main() {
    Node* head = nullptr;
    int n, value;

    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "\nOriginal Linked List: ";
    displayList(head);

    reverseList(head);

    cout << "Reversed Linked List: ";
    displayList(head);

    return 0;
}
