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

Node* buildTree(int inorder[], int postorder[],
                int inStart, int inEnd, int& postIndex) {

    if (inStart > inEnd)
        return nullptr;

    int curr = postorder[postIndex--];
    Node* root = new Node(curr);

    if (inStart == inEnd)
        return root;

    int pos = findIndex(inorder, inStart, inEnd, curr);

    root->right = buildTree(inorder, postorder, pos + 1, inEnd, postIndex);
    root->left  = buildTree(inorder, postorder, inStart, pos - 1, postIndex);

    return root;
}

void printInorder(Node* root) {
    if (root == nullptr) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    int inorder[]   = {4, 2, 5, 1, 6, 3};
    int postorder[] = {4, 5, 2, 6, 3, 1};

    int n = sizeof(inorder) / sizeof(inorder[0]);
    int postIndex = n - 1;

    Node* root = buildTree(inorder, postorder, 0, n - 1, postIndex);

    cout << "Tree constructed. Inorder traversal is:\n";
    printInorder(root);

    return 0;
}
