#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;   
    Node* right;  
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

Node* insertBST(Node* root, int key) {
    if (!root) return new Node(key);
    if (key < root->data)
        root->left = insertBST(root->left, key);
    else
        root->right = insertBST(root->right, key);
    return root;
}

void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    bstToDLL(root->left, head, prev);

    if (prev == NULL)
        head = root;
    else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* mergeDLL(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node* head;
    if (head1->data < head2->data) {
        head = head1;
        head1 = head1->right;
    } else {
        head = head2;
        head2 = head2->right;
    }

    Node* curr = head;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            curr->right = head1;
            head1->left = curr;
            head1 = head1->right;
        } else {
            curr->right = head2;
            head2->left = curr;
            head2 = head2->right;
        }
        curr = curr->right;
    }

    if (head1) {
        curr->right = head1;
        head1->left = curr;
    }
    if (head2) {
        curr->right = head2;
        head2->left = curr;
    }

    return head;
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " <—> ";
        head = head->right;
    }
    cout << "null\n";
}

int main() {
    Node *T1 = NULL, *T2 = NULL;

    T1 = insertBST(T1, 20);
    T1 = insertBST(T1, 10);
    T1 = insertBST(T1, 30);
    T1 = insertBST(T1, 25);
    T1 = insertBST(T1, 100);

    T2 = insertBST(T2, 50);
    T2 = insertBST(T2, 5);
    T2 = insertBST(T2, 70);

    Node *head1 = NULL, *prev1 = NULL;
    bstToDLL(T1, head1, prev1);

    Node *head2 = NULL, *prev2 = NULL;
    bstToDLL(T2, head2, prev2);

    Node* mergedHead = mergeDLL(head1, head2);

    printDLL(mergedHead);

    return 0;
}
