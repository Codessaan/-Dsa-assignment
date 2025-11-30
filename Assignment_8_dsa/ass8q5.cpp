#include <iostream>
#include <stack>
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

void inorderIterative(Node* root) {
    stack<Node*> s;
    Node* curr = root;

    while (curr != nullptr || !s.empty()) {

        while (curr != nullptr) {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();

        cout << curr->data << " ";  

        curr = curr->right;
    }
}

int main() {
    Node* root = nullptr;

    int arr[] = {50, 30, 20, 40, 70, 60, 80};
    for (int x : arr)
        root = insertNode(root, x);

    cout << "Inorder Traversal (Non-Recursive): ";
    inorderIterative(root);

    return 0;
}
