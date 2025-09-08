#include <iostream>
#include <string>
using namespace std;
#define MAX 100
int main() {
    char stackArr[MAX];
    int top = -1;
    string str;
    cout << "Enter a string: ";
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (top == MAX - 1) {
            cout << "Stack Overflow! String too long." << endl;
        }
        else{
            stackArr[++top] = str[i];
        }
    }
    cout << "Reversed string: ";
    while (top != -1) {
        cout << stackArr[top];
        top--;
    }
    cout << endl;
    return 0;
}
