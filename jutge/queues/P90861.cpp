#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector< queue<string> > persons(n);
    queue<string> departs;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream stream(line);
        string name;
        while (stream >> name) persons[i].push(name);
    }

    cin.ignore();

    string instruction;
    while (cin >> instruction) {
        if (instruction == "LEAVES") {
            int s;
            cin >> s;
            if ((s > 0 && s <= n) && !persons[s - 1].empty()) {
                departs.push(persons[s - 1].front());
                persons[s - 1].pop();
            }
        }
        else if (instruction == "ENTERS") {
            string name;
            int s;
            cin >> name >> s;
            if (s > 0 && s <= n) persons[s - 1].push(name);
        }
        else if (instruction == "END") break;
    }

    cout << "DEPARTS" << endl << "-------" << endl;
    while (!departs.empty()) {
        cout << departs.front() << endl;
        departs.pop();
    }
    cout << endl;

    cout << "FINAL CONTENTS" << endl << "--------------" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "queue " << i + 1 << ":";
        while (!persons[i].empty()) {
            cout << " " << persons[i].front();
            persons[i].pop();
        }
        cout << endl;
    }

    return 0;
}