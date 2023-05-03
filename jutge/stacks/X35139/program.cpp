#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "stack.hpp"

int main()
{
    Stack<string> s;
    string command;
    while (cin >> command) {
        if (command == "push") {
            string word;
            cin >> word;
            s.push(word);
        } else if (command == "pop") {
            s.pop();
        } else if (command == "top") {
            cout << s.top() << endl;
        } else if (command == "size") {
            cout << s.size() << endl;
        } else if (command == "removeFirstOccurrence") {
            string word;
            cin >> word;
            s.removeFirstOccurrence(word);
        }
    }
}
