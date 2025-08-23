#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string str ;
    cout << "Enter string : ";
    getline(cin, str);
   
    reverse(str.begin(), str.end());
    cout << " resulted string: " << str << endl;
    return 0;
}
