#include <iostream>
#include <stack>
#include <cctype>
#include <string>
using namespace std;
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
bool isLeftAssociative(char op) {
    if (op == '^') return false; 
    return true;
}
string infixToPostfix(string infix) {
    stack<char> st;
    string postfix = "";
    for (char ch : infix) {
        if (isalnum(ch)) {
            postfix += ch;
        } 
        else if (ch == '(') {
            st.push(ch);
        } 
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop(); 
        } 
        else {
            while (!st.empty() && precedence(st.top()) > 0 &&
                  (precedence(st.top()) > precedence(ch) ||
                  (precedence(st.top()) == precedence(ch) && isLeftAssociative(ch)))) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout << "Enter an Infix expression: ";
    cin >> infix;
    string postfix = infixToPostfix(infix);
    cout << "Postfix expression: " << postfix << endl;
    return 0;
}
