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
        cout << "List is empty.";
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

// Function to count and delete all occurrences of a given key
int deleteAllOccurrences(Node*& head, int key) {
    int count = 0;

    // Delete occurrences at the beginning
    while (head != nullptr && head->data == key) {
        Node* temp = head;
        head = head->next;
        delete temp;
        count++;
    }

    // If list becomes empty after deletion
    if (head == nullptr)
        return count;

    Node* current = head;
    while (current->next != nullptr) {
        if (current->next->data == key) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            count++;
        } else {
            current = current->next;
        }
    }

    return count;
}

// Main function
int main() {
    Node* head = nullptr;
    int n, value, key;

    cout << "Enter number of elements in the linked list: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> value;
        insertAtEnd(head, value);
    }

    cout << "Enter the key to delete: ";
    cin >> key;

    cout << "\nOriginal Linked List: ";
    displayList(head);

    int count = deleteAllOccurrences(head, key);

    cout << "\nCount of key " << key << ": " << count << endl;
    cout << "Updated Linked List: ";
    displayList(head);

    return 0;
}
