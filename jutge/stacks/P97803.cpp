#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    cin.ignore();
    vector< stack<string> > books(n);
    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        istringstream stream(line);
        string name;
        while (stream >> name) books[i].push(name);
    }

    cin.ignore();

    string instruction;
    while (cin >> instruction) {
        if (instruction == "LOAN") {
            int s;
            cin >> s;
            if ((s > 0 && s <= n) && !books[s - 1].empty()) books[s - 1].pop();
        }
        else if (instruction == "RETURN") {
            string name;
            int s;
            cin >> name >> s;
            if (s > 0 && s <= n) books[s - 1].push(name);
        }
    }

    for (int i = 0; i < n; ++i) {
        cout << "Stack " << i + 1 << ":";
        stack<string> tmp;
        while (!books[i].empty()) {
            tmp.push(books[i].top());
            books[i].pop();
        }
        while (!tmp.empty()) {
            cout << " " << tmp.top();
            tmp.pop();
        }
        cout << endl;
    }

    return 0;
}