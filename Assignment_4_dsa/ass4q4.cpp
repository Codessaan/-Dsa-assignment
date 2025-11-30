#include <iostream>
#include <queue>
#include <string>
#include <sstream>
#include <vector>
#include <cctype>   

using namespace std;

void firstNonRepeating(const vector<char>& stream) {
    queue<char> q;
    int freq[256] = {0}; 

    for (size_t i = 0; i < stream.size(); ++i) {
        char ch = stream[i];
        unsigned char uch = static_cast<unsigned char>(ch);
        ++freq[uch];

        q.push(ch);

        
        while (!q.empty() && freq[static_cast<unsigned char>(q.front())] > 1) {
            q.pop();
        }

        if (q.empty())
            cout << "-1 ";
        else
            cout << q.front() << ' ';
    }
    cout << '\n';
}

int main() {
    cout << "Enter characters (e.g. 'a a b c' or 'aabc'):\n";
    string line;
    if (!getline(cin, line)) return 0;

    vector<char> stream;
    istringstream iss(line);
    string token;

    if (line.find(' ') != string::npos) {
        while (iss >> token) {
            if (!token.empty()) stream.push_back(token[0]);
        }
    } else {
        for (size_t i = 0; i < line.size(); ++i) {
            if (!isspace(static_cast<unsigned char>(line[i])))
                stream.push_back(line[i]);
        }
    }

    if (stream.empty()) {
        cout << "No valid input provided.\n";
        return 0;
    }

    cout << "Output: ";
    firstNonRepeating(stream);

    return 0;
}
