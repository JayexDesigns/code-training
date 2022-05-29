#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>

using namespace std;

#include "queue.hpp"

string getLast(string s, int len)
{
    if (int(s.size()) <= len) return s;
    return s.substr(int(s.size())-len);
}

bool isSuffix(string s, string suffix)
{
    return getLast(s, suffix.size()) == suffix;
}

string removeSuffix(string s, string suffix)
{
    return s.substr(0, int(s.size())-int(suffix.size()));
}

int main()
{
    map<string, Queue<int> > id2q;
    string command;
    while (cin >> command) {
        if (isSuffix(command,".push")) {
            string id = removeSuffix(command, ".push");
            int x;
            cin >> x;
            id2q[id].push(x);
        } else if (isSuffix(command,".pop")) {
            string id = removeSuffix(command, ".pop");
            id2q[id].pop();
        } else if (command == "<<") {
            string id;
            cin >> id;
            cout << id2q[id] << endl;
        } else {
            string id = command;
            cin >> command;
            if (command != "+=") {
                cerr << "Command error " << command << endl;
                exit(1);
            }
            string id2;
            cin >> id2;
            id2q[id] += id2q[id2];
        }
    }
}
