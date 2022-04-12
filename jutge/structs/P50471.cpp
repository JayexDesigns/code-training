#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct contestant {
    string name;
    int wager;
};

string getBestContestant(vector<contestant> contestants, int finalPrice) {
    int bestIndex = -1;
    for (int i = 0; i < (int)contestants.size(); ++i) {
        if (contestants[i].wager <= finalPrice) {
            if (bestIndex == -1) bestIndex = i;
            else {
                if (contestants[bestIndex].wager < contestants[i].wager) bestIndex = i;
            }
        }
    }
    return (bestIndex == -1) ? "" : contestants[bestIndex].name;
}

int main() {
    int n;
    vector<contestant> contestants = {};
    cin >> n;
    for (int i = 0; i < n; ++i) {
        contestant person;
        cin >> person.name;
        cin >> person.wager;
        contestants.push_back(person);
    }
    int finalPrice;
    cin >> finalPrice;
    string bestContestant = getBestContestant(contestants, finalPrice);
    if (bestContestant == "") cout << "CAP GUANYADOR" << endl;
    else cout << "guanyador/a: " << bestContestant << endl;
    return 0;
}