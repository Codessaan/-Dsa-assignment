#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

Node* insertNode(Node* root, int key) {
    if (root == nullptr)
        return new Node(key);

    if (key < root->data)
        root->left = insertNode(root->left, key);
    else
        root->right = insertNode(root->right, key);

    return root;
}

Node* searchRecursive(Node* root, int key) {
    if (root == nullptr || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

Node* searchNonRecursive(Node* root, int key) {
    while (root != nullptr) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return nullptr;
}

Node* findMax(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->right != nullptr)
        root = root->right;

    return root;
}

Node* findMin(Node* root) {
    if (root == nullptr) return nullptr;

    while (root->left != nullptr)
        root = root->left;

    return root;
}

Node* inorderSuccessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    if (target->right != nullptr)
        return findMin(target->right);

    Node* successor = nullptr;
    while (root != nullptr) {
        if (target->data < root->data) {
            successor = root;
            root = root->left;
        }
        else if (target->data > root->data)
            root = root->right;
        else
            break;
    }
    return successor;
}

Node* inorderPredecessor(Node* root, Node* target) {
    if (target == nullptr) return nullptr;

    if (target->left != nullptr)
        return findMax(target->left);

    Node* predecessor = nullptr;
    while (root != nullptr) {
        if (target->data > root->data) {
            predecessor = root;
            root = root->right;
        }
        else if (target->data < root->data)
            root = root->left;
        else
            break;
    }
    return predecessor;
}

void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    Node* root = nullptr;

    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Inorder Traversal: ";
    inorder(root);
    cout << "\n";

    int key = 40;
    cout << "\nSearching for " << key << "...\n";

    Node* r1 = searchRecursive(root, key);
    Node* r2 = searchNonRecursive(root, key);

    cout << "Recursive Search: " << (r1 ? "Found" : "Not Found") << endl;
    cout << "Non-Recursive Search: " << (r2 ? "Found" : "Not Found") << endl;

    cout << "\nMinimum: " << findMin(root)->data << endl;
    cout << "Maximum: " << findMax(root)->data << endl;

    Node* succ = inorderSuccessor(root, r1);
    Node* pred = inorderPredecessor(root, r1);

    cout << "\nInorder Successor of " << r1->data << ": "
         << (succ ? to_string(succ->data) : "None") << endl;

    cout << "Inorder Predecessor of " << r1->data << ": "
         << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
