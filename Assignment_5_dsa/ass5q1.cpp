#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Head pointer to start of linked list
Node* head = nullptr;

// Function to insert at the beginning
void insertAtBeginning(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
    cout << "Inserted " << value << " at the beginning.\n";
}

// Function to insert at the end
void insertAtEnd(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
    cout << "Inserted " << value << " at the end.\n";
}

// Function to insert before or after a specific value
void insertSpecific(int value, int target, bool after) {
    Node* newNode = new Node();
    newNode->data = value;

    if (head == nullptr) {
        cout << "List is empty.\n";
        delete newNode;
        return;
    }

    Node* temp = head;

    // If inserting before the head
    if (!after && head->data == target) {
        newNode->next = head;
        head = newNode;
        cout << "Inserted " << value << " before " << target << ".\n";
        return;
    }

    while (temp != nullptr) {
        if (after && temp->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " after " << target << ".\n";
            return;
        }
        if (!after && temp->next != nullptr && temp->next->data == target) {
            newNode->next = temp->next;
            temp->next = newNode;
            cout << "Inserted " << value << " before " << target << ".\n";
            return;
        }
        temp = temp->next;
    }

    cout << "Target node " << target << " not found.\n";
    delete newNode;
}

// Function to delete from beginning
void deleteFromBeginning() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    Node* temp = head;
    head = head->next;
    cout << "Deleted node with value " << temp->data << " from beginning.\n";
    delete temp;
}

// Function to delete from end
void deleteFromEnd() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->next == nullptr) {
        cout << "Deleted node with value " << head->data << " from end.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr)
        temp = temp->next;

    cout << "Deleted node with value " << temp->next->data << " from end.\n";
    delete temp->next;
    temp->next = nullptr;
}

// Function to delete a specific node by value
void deleteSpecific(int value) {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Deleted node with value " << value << ".\n";
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr && temp->next->data != value)
        temp = temp->next;

    if (temp->next == nullptr) {
        cout << "Node with value " << value << " not found.\n";
        return;
    }

    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    cout << "Deleted node with value " << value << ".\n";
    delete toDelete;
}

// Function to search for a node and display its position
void searchNode(int value) {
    Node* temp = head;
    int position = 1;

    while (temp != nullptr) {
        if (temp->data == value) {
            cout << "Node with value " << value << " found at position " << position << ".\n";
            return;
        }
        temp = temp->next;
        position++;
    }

    cout << "Node with value " << value << " not found.\n";
}

// Function to display all node values
void displayList() {
    if (head == nullptr) {
        cout << "List is empty.\n";
        return;
    }

    cout << "Linked List: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Main Menu
int main() {
    int choice, value, target;
    bool after;

    while (true) {
        cout << "\n------ Singly Linked List Menu ------\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert Before a Node\n";
        cout << "4. Insert After a Node\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete a Specific Node\n";
        cout << "8. Search for a Node\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "-----------------------------------\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                insertAtBeginning(value);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> value;
                insertAtEnd(value);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value (before which to insert): ";
                cin >> target;
                insertSpecific(value, target, false);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> value;
                cout << "Enter target node value (after which to insert): ";
                cin >> target;
                insertSpecific(value, target, true);
                break;

            case 5:
                deleteFromBeginning();
                break;

            case 6:
                deleteFromEnd();
                break;

            case 7:
                cout << "Enter value of node to delete: ";
                cin >> value;
                deleteSpecific(value);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> value;
                searchNode(value);
                break;

            case 9:
                displayList();
                break;

            case 10:
                cout << "Exiting program...\n";
                return 0;

            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}
