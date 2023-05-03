#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "queue.hpp"

int main()
{
    Queue<double> q;
    string command;
    while (cin >> command) {
        if (command == "push") {
            double x;
            cin >> x;
            q.push(x);
        } else if (command == "pop") {
            q.pop();
        } else if (command == "front") {
            cout << q.front() << endl;
        } else if (command == "size") {
            cout << q.size() << endl;
        } else if (command == "*=") {
            double factor;
            cin >> factor;
            q *= factor;
        }
    }
}
