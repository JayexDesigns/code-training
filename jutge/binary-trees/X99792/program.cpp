#include <iostream>
#include <sstream>
#include <string>
#include <list>
#include "BinaryTree.hpp"

using namespace std;

int getLeafs(const BinaryTree<int>& t, list<int>& l) {
    if (t.isEmpty()) return 0;

    if (l.empty()) {
        if (t.getLeft().isEmpty() && t.getRight().isEmpty()) return 1;
        else {
            int n1 = getLeafs(t.getLeft(), l);
            int n2 = getLeafs(t.getRight(), l);
            return n1 + n2;
        }
    }

    else {
        list<int> newL = l;
        if (l.front() == t.getRoot()) {
            newL.pop_front();
            if (newL.empty() && t.getLeft().isEmpty() && t.getRight().isEmpty()) return 1;
        }
        int n1 = getLeafs(t.getLeft(), newL);
        int n2 = getLeafs(t.getRight(), newL);
        return n1 + n2;
    }
}

int main() {
    BinaryTree<int> t;
    string line;
    getline(cin, line);
    readStringTree(line, t);
    // cout << "test" << endl;
    // cout << t;

    while(getline(cin, line)) {
        istringstream stream(line);
        int value;
        list<int> l;
        while(stream >> value) {
            l.push_back(value);
        }
        cout << getLeafs(t, l) << endl;
    }

    return 0;
}