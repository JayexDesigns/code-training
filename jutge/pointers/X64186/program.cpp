#include <iostream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

#include "list.hpp"

struct Container {
    string word;
    Container() {
        word = "";
    }
    Container(const Container &c)
    {
        if (this == &c) return;
    	word = c.word;
    }
	Container &operator=(const Container &c)
	{
    	word = c.word;
        return *this;
	}
};

int main()
{
    List<Container> l;
    List<Container>::iterator it1 = l.begin();
    List<Container>::iterator it1aux = l.begin();
    List<Container>::iterator it2 = l.begin();
    List<Container>::iterator it2aux = l.begin();
    string command;
    while (cin >> command) {
        //cout << "command " << command << endl;
        if (command == "push_back") {
            Container c;
            cin >> c.word;
            l.push_back(c);
        } else if (command == "push_front") {
            Container c;
            cin >> c.word;
            l.push_front(c);
        } else if (command == "pop_back") {
            l.pop_back();
        } else if (command == "pop_front") {
            l.pop_front();
        } else if (command == "it1++") {
            it1++;
            it1aux++;
        } else if (command == "it1--") {
            it1--;
            it1aux--;
        } else if (command == "*it1") {
            cout << (*it1aux).word << endl;
        } else if (command == "it2++") {
            it2++;
            it2aux++;
        } else if (command == "it2--") {
            it2--;
            it2aux--;
        } else if (command == "*it2") {
            cout << (*it2aux).word << endl;
        } else if (command == "swapPositionsOfItems") {
            l.swapPositionsOfItems(it1, it2);
        } else {
            cout << "Wrong command " << endl;
        }
    }
}
