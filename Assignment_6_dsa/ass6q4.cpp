#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

Node* head = NULL;

void create(char arr[], int n) {
    Node *temp, *last;
    head = new Node{arr[0], NULL, NULL};
    last = head;

    for (int i = 1; i < n; i++) {
        temp = new Node{arr[i], last, NULL};
        last->next = temp;
        last = temp;
    }
}

bool isPalindrome() {
    if (head == NULL) return true;

    Node *left = head, *right = head;

    while (right->next != NULL)
        right = right->next;

    while (left != right && left->prev != right) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    char arr[] = {'L', 'E', 'V', 'E', 'L'};
    int n = 5;

    create(arr, n);

    if (isPalindrome())
        cout << "True";
    else
        cout << "False";

    return 0;
}
