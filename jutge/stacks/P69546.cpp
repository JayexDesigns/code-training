#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector< stack<string> > cards;
        vector<int> candy(n, 0);
        for (int i = 0; i < n; ++i) {
            string name;
            stack<string> s;
            while (name != "FI") {
                cin >> name;
                if (name != "FI") s.push(name);
            }
            cards.push_back(s);
        }

        int firstChild = 1;
        int secondChild = 1;
        int cardNum = 1;
        while (firstChild != 0 || secondChild != 0 || cardNum != 0) {
            cin >> firstChild;
            cin >> secondChild;
            cin >> cardNum;

            while (cardNum > 0) {
                if (cards[secondChild - 1].empty()) {
                    candy[secondChild - 1] += cardNum;
                    break;
                }
                else {
                    cards[firstChild - 1].push(cards[secondChild - 1].top());
                    cards[secondChild - 1].pop();
                    cardNum--;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << candy[i];
            while (!cards[i].empty()) {
                cout << " " << cards[i].top();
                cards[i].pop();
            }
            cout << endl;
        }
        cout << "----------" << endl;
    }
    return 0;
}