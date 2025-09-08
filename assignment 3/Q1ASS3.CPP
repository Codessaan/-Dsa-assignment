#include <iostream>
using namespace std;
#define MAX 10
int main() {
    int stackArr[MAX];
    int top = -1;
    int choice, value;
    do {
        cout << "\nStack Menu : " << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Check if Empty" << endl;
        cout << "6. Check if Full" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            if (top == MAX - 1) {
                cout << "Cannot push " << endl;
            } else {
                cout << "Enter value to push: ";
                cin >> value;
                stackArr[++top] = value;
                cout << value << " pushed into stack." << endl;
            }
            break;
        case 2:
            if (top == -1) {
                cout << "cannot pop" << endl;
            } else {
                cout << stackArr[top--] << " popped from stack." << endl;
            }
            break;
        case 3:
            if (top == -1) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Top element is: " << stackArr[top] << endl;
            }
            break;
        case 4:
            if (top == -1) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack elements (top to bottom): ";
                for (int i = top; i >= 0; i--) {
                    cout << stackArr[i] << " ";
                }
                cout << endl;
            }
            break;
        case 5:
            if (top == -1)
                cout << "Stack is Empty." << endl;
            else
                cout << "Stack is not Empty." << endl;
            break;
        case 6:
            if (top == MAX - 1)
                cout << "Stack is Full." << endl;
            else
                cout << "Stack is not Full." << endl;
            break;
        case 0:
            cout << "Exit" << endl;
            break;
        default:
            cout << "Invalid choice " << endl;
        }
    } while (choice != 0);
    return 0;
}
