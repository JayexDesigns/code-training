#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    string input;
    while (cin >> input) {
        stack<char> s;
        bool valid = true;
        for (int i = 0; i < (int)input.size() && valid; ++i) {
            if (s.empty()) s.push(input[i]);
            else if (input[i] == '(' || input[i] == '[' || input[i] == '{') s.push(input[i]);
            else {
                if (s.top() == '(' && input[i] != ')') valid = false;
                else if (s.top() == '(' && input[i] == ')') s.pop();
                else if (s.top() == '[' && input[i] != ']') valid = false;
                else if (s.top() == '[' && input[i] == ']') s.pop();
                else if (s.top() == '{' && input[i] != '}') valid = false;
                else if (s.top() == '{' && input[i] == '}') s.pop();
            }
        }
        if (!valid || !s.empty()) cout << input << " is incorrect" << endl;
        else cout << input << " is correct" << endl;
    }
    return 0;
}