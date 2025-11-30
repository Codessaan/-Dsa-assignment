#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end
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
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << "->";
        temp = temp->next;
    }
    cout << endl;
}

// Function to find the middle node of the linked list
void findMiddle(Node* head) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    Node* slow = head;
    Node* fast = head;

    // Move 'fast' by 2 steps and 'slow' by 1 step
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    cout << "Middle element: " << slow->data << endl;
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

    cout << "\nLinked List: ";
    displayList(head);

    findMiddle(head);

    return 0;
}
