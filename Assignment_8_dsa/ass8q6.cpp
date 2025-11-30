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

int findIndex(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

Node* buildTree(int preorder[], int inorder[], int inStart, int inEnd, int& preIndex) {
    if (inStart > inEnd)
        return nullptr;

    int curr = preorder[preIndex++];
    Node* root = new Node(curr);

    if (inStart == inEnd)
        return root;

    int pos = findIndex(inorder, inStart, inEnd, curr);

    root->left = buildTree(preorder, inorder, inStart, pos - 1, preIndex);
    root->right = buildTree(preorder, inorder, pos + 1, inEnd, preIndex);

    return root;
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int preorder[] = {1, 2, 4, 5, 3, 6};
    int inorder[]  = {4, 2, 5, 1, 6, 3};

    int n = sizeof(preorder) / sizeof(preorder[0]);
    int preIndex = 0;

    Node* root = buildTree(preorder, inorder, 0, n - 1, preIndex);

    cout << "Tree constructed. Inorder traversal is:\n";
    printInorder(root);

    return 0;
}
