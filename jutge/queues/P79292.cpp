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
    vector< vector< queue<string> > > persons(n, vector< queue<string> >(4));
    queue<string> departs;
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream stream(line);
        string name, graduation;
        while (stream >> name >> graduation) {
            if (graduation == "soldier") persons[i][3].push(name);
            else if (graduation == "sergeant") persons[i][2].push(name);
            else if (graduation == "captain") persons[i][1].push(name);
            else if (graduation == "colonel") persons[i][0].push(name);
        }
    }

    cin.ignore();

    string instruction;
    while (cin >> instruction) {
        if (instruction == "LEAVES") {
            int s;
            cin >> s;
            if (s > 0 && s <= n) {
                for (int i = 0; i < 4; ++i) {
                    if (!persons[s - 1][i].empty()) {
                        departs.push(persons[s - 1][i].front());
                        persons[s - 1][i].pop();
                        break;
                    }
                }
            }
        }
        else if (instruction == "ENTERS") {
            string name, graduation;
            int s;
            cin >> name >> graduation >> s;
            if (s > 0 && s <= n) {
                if (graduation == "soldier") persons[s - 1][3].push(name);
                else if (graduation == "sergeant") persons[s - 1][2].push(name);
                else if (graduation == "captain") persons[s - 1][1].push(name);
                else if (graduation == "colonel") persons[s - 1][0].push(name);
            }
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
        for (int j = 0; j < 4; ++j) {
            while (!persons[i][j].empty()) {
                cout << " " << persons[i][j].front();
                persons[i][j].pop();
            }
        }
        cout << endl;
    }

    return 0;
}