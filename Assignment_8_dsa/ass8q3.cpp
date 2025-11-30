#include <iostream>
#include <algorithm>
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
    else if (key > root->data)
        root->right = insertNode(root->right, key);
    else
        cout << "Duplicate not allowed: " << key << endl;

    return root;
}

Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        
        if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        Node* temp = findMin(root->right);  
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int maxDepth(Node* root) {
    if (root == nullptr) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

int minDepth(Node* root) {
    if (root == nullptr) return 0;

    if (root->left == nullptr)
        return minDepth(root->right) + 1;

    if (root->right == nullptr)
        return minDepth(root->left) + 1;

    return min(minDepth(root->left), minDepth(root->right)) + 1;
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

    cout << "\n\nDeleting 20...\n";
    root = deleteNode(root, 20);
    inorder(root);

    cout << "\nDeleting 30...\n";
    root = deleteNode(root, 30);
    inorder(root);

    cout << "\nDeleting 50...\n";
    root = deleteNode(root, 50);
    inorder(root);

    cout << "\n\nMaximum Depth of BST: " << maxDepth(root);
    cout << "\nMinimum Depth of BST: " << minDepth(root) << endl;

    return 0;
}
