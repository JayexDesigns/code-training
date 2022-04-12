#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

queue<string> radixSort(queue<string> &q) {
    queue<string> s = q;
    vector< queue<string> > v(26);

    for (int exp = 1; exp <= (int)s.front().size(); ++exp) {
        while (!s.empty()) {
            string word = s.front();
            int pos = word[word.size() - exp] - 97;
            v[pos].push(word);
            s.pop();
        }

        for (int i = 0; i < 26; ++i) {
            while (!v[i].empty()) {
                s.push(v[i].front());
                v[i].pop();
            }
        }
    }


    return s;
}

int main() {
    string line;
    getline(cin, line);
    istringstream stream(line);
    queue<string> elems;
    string elem;
    while (stream >> elem) elems.push(elem);

    queue<string> sorted = radixSort(elems);

    while (!sorted.empty()) {
        cout << sorted.front();
        sorted.pop();
        if (!sorted.empty()) cout << " ";
    }
    cout << endl;

    return 0;
}