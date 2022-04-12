#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isNumber(const string& s) {
    string::const_iterator it = s.begin();
    while (it != s.end() && isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}

void operate(stack<int>& s, const string& operation) {
    int firstNum = s.top();
    s.pop();
    int secondNum = s.top();
    s.pop();
    int res;
    if (operation == "+") res = secondNum + firstNum;
    else if (operation == "-") res = secondNum - firstNum;
    else if (operation == "*") res = secondNum * firstNum;
    s.push(res);
}

int main() {
    while (cin) {
        string a;
        stack<int> s;

        while (cin >> a) {
            if (isNumber(a)) s.push(stoi(a));
            else operate(s, a);

            if (cin.get() == '\n') break;
        }

        if (!s.empty()) cout << s.top() << endl;
    }
    return 0;
}