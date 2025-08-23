#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    cout << "Enter string 1: ";
    getline(cin, str1);
    cout << "Enter string 2: ";
    getline(cin, str2);
    // concatination 
    str1 = str1 + str2;   
    cout << " resulted string: " << str1 << endl;

    return 0;
}
