#include <iostream>
using namespace std;

struct CNode {
    int data;
    CNode* next;
};

CNode* Chead = NULL;

void CinsertBegin(int val) {
    CNode* temp = new CNode{val, NULL};
    if (Chead == NULL) {
        Chead = temp;
        temp->next = Chead;
        return;
    }
    CNode* last = Chead;
    while (last->next != Chead)
        last = last->next;

    temp->next = Chead;
    last->next = temp;
    Chead = temp;
}
void CinsertEnd(int val) {
    CNode* temp = new CNode{val, NULL};
    if (Chead == NULL) {
        Chead = temp;
        temp->next = Chead;
        return;
    }
    CNode* last = Chead;
    while (last->next != Chead)
        last = last->next;

    last->next = temp;
    temp->next = Chead;
}

void CinsertAfter(int key, int val) {
    if (Chead == NULL) return;
    CNode* curr = Chead;
    do {
        if (curr->data == key) {
            CNode* temp = new CNode{val, curr->next};
            curr->next = temp;
            return;
        }
        curr = curr->next;
    } while (curr != Chead);
}

void CdeleteNode(int key) {
    if (Chead == NULL) return;

    CNode* curr = Chead;
    CNode* prev = NULL;

    do {
        if (curr->data == key) break;
        prev = curr;
        curr = curr->next;
    } while (curr != Chead);

    if (curr->data != key) return;   

    if (curr == Chead) {
        CNode* last = Chead;
        while (last->next != Chead)
            last = last->next;

        if (last == Chead) { 
            delete Chead;
            Chead = NULL;
            return;
        }

        last->next = Chead->next;
        Chead = Chead->next;
        delete curr;
    }
    else {
        prev->next = curr->next;
        delete curr;
    }
}

bool Csearch(int key) {
    if (Chead == NULL) return false;
    CNode* curr = Chead;
    do {
        if (curr->data == key)
            return true;
        curr = curr->next;
    } while (curr != Chead);
    return false;
}

void Cdisplay() {
    if (Chead == NULL) {
        cout << "List is empty\n";
        return;
    }
    CNode* curr = Chead;
    do {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != Chead);
    cout << endl;
}
struct DNode {
    int data;
    DNode* prev;
    DNode* next;
};

DNode* Dhead = NULL;

void DinsertBegin(int val) {
    DNode* temp = new DNode{val, NULL, Dhead};
    if (Dhead != NULL)
        Dhead->prev = temp;
    Dhead = temp;
}

void DinsertEnd(int val) {
    DNode* temp = new DNode{val, NULL, NULL};
    if (Dhead == NULL) {
        Dhead = temp;
        return;
    }
    DNode* curr = Dhead;
    while (curr->next != NULL)
        curr = curr->next;

    curr->next = temp;
    temp->prev = curr;
}

void DinsertAfter(int key, int val) {
    DNode* curr = Dhead;
    while (curr != NULL && curr->data != key)
        curr = curr->next;
    if (curr == NULL) return;

    DNode* temp = new DNode{val, curr, curr->next};
    if (curr->next != NULL)
        curr->next->prev = temp;
    curr->next = temp;
}

void DinsertBefore(int key, int val) {
    if (Dhead == NULL) return;

    DNode* curr = Dhead;
    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) return;

    DNode* temp = new DNode{val, curr->prev, curr};
    if (curr->prev != NULL)
        curr->prev->next = temp;
    else
        Dhead = temp;

    curr->prev = temp;
}

void DdeleteNode(int key) {
    DNode* curr = Dhead;
    while (curr != NULL && curr->data != key)
        curr = curr->next;

    if (curr == NULL) return;

    if (curr->prev != NULL)
        curr->prev->next = curr->next;
    else
        Dhead = curr->next;

    if (curr->next != NULL)
        curr->next->prev = curr->prev;

    delete curr;
}

bool Dsearch(int key) {
    DNode* curr = Dhead;
    while (curr != NULL) {
        if (curr->data == key)
            return true;
        curr = curr->next;
    }
    return false;
}

void Ddisplay() {
    DNode* curr = Dhead;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    int choice, type, val, key;

    while (true) {
        cout << "\n--- MAIN MENU ---\n";
        cout << "1. Circular Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> type;

        if (type == 3) break;

        cout << "1. Insert Begin\n2. Insert End\n3. Insert After Node\n"
             << "4. Insert Before Node (DLL only)\n5. Delete Node\n"
             << "6. Search Node\n7. Display\n8. Back\n";

        cout << "Enter your operation: ";
        cin >> choice;

        switch (type) {

        case 1:  
            switch (choice) {
            case 1: cout << "Value: "; cin >> val; CinsertBegin(val); break;
            case 2: cout << "Value: "; cin >> val; CinsertEnd(val); break;
            case 3: cout << "After which value? "; cin >> key;
                    cout << "Value: "; cin >> val;
                    CinsertAfter(key, val); break;
            case 5: cout << "Delete which value? "; cin >> key; CdeleteNode(key); break;
            case 6: cout << "Search value: "; cin >> key;
                    cout << (Csearch(key) ? "Found\n" : "Not Found\n"); break;
            case 7: Cdisplay(); break;
            }
            break;

        case 2: 
            switch (choice) {
            case 1: cout << "Value: "; cin >> val; DinsertBegin(val); break;
            case 2: cout << "Value: "; cin >> val; DinsertEnd(val); break;
            case 3: cout << "After which value? "; cin >> key;
                    cout << "Value: "; cin >> val;
                    DinsertAfter(key, val); break;
            case 4: cout << "Before which value? "; cin >> key;
                    cout << "Value: "; cin >> val;
                    DinsertBefore(key, val); break;
            case 5: cout << "Delete which value? "; cin >> key; DdeleteNode(key); break;
            case 6: cout << "Search value: "; cin >> key;
                    cout << (Dsearch(key) ? "Found\n" : "Not Found\n"); break;
            case 7: Ddisplay(); break;
            }
        }
    }

    return 0;
}
