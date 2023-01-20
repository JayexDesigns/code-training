#include <iostream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

void printList(list<int>& l) {
    list<int>::iterator it;
    for (it = l.begin(); it != l.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
}

int main() {
    string line;
    list<int> l;
    list<int> maxCount;

    while(getline(cin, line)) {
        istringstream stream(line);
        string operation;
        stream >> operation;

        if (operation == "push_front" || operation == "push_back") {
            int n;
            if (!(stream >> n)) {
                cout << "error" << endl;
                continue;
            }

            if (operation == "push_front") {
                if (l.size() == 0) maxCount.push_front(1);
                else if (l.front() == n) ++maxCount.front();
                else if (l.front() != n) maxCount.push_front(1);
                l.push_front(n);
            }
            else if (operation == "push_back") {
                if (l.size() == 0) maxCount.push_back(1);
                else if (l.back() == n) ++maxCount.back();
                else if (l.back() != n) maxCount.push_back(1);
                l.push_back(n);
            }
        }

        else if (operation == "pop_front" || operation == "pop_back") {
            if (l.size() == 0) {
                cout << "error" << endl;
                continue;
            }

            if (operation == "pop_front") {
                int n = l.front();
                l.pop_front();
                if (l.size() == 0 || maxCount.front() == 1) maxCount.pop_front();
                else if (maxCount.front() != 1) --maxCount.front();
            }
            else if (operation == "pop_back") {
                int n = l.back();
                l.pop_back();
                if (l.size() == 0 || maxCount.back() == 1) maxCount.pop_back();
                else if (maxCount.back() != 1) --maxCount.back();
            }
        }

        else if (operation == "max_equal_left") cout << (maxCount.size() == 0 ? 0 : maxCount.front()) << endl;
        else if (operation == "max_equal_right") cout << (maxCount.size() == 0 ? 0 : maxCount.back()) << endl;
        else if (operation == "print") printList(l);
        else if (operation == "printCount") printList(maxCount);
    }

    return 0;
}