#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main() {
    string input;
    while (getline(cin, input)) {
        istringstream stream(input);
        int n;

        stack <int> firstStack;
        while(stream >> n) firstStack.push(n);

        stack <int> tmpStack = firstStack;
        stack <int> secondStack;
        while (!tmpStack.empty()) {
            secondStack.push(tmpStack.top());
            tmpStack.pop();
        }

        bool palindrome = true;
        while (!firstStack.empty()) {
            if (firstStack.top() != secondStack.top()) {
                palindrome = false;
                break;
            }
            firstStack.pop();
            secondStack.pop();
        }

        if (palindrome) cout << "It is a palindrome." << endl;
        else cout << "It is NOT a palindrome." << endl;
    }
    return 0;
}