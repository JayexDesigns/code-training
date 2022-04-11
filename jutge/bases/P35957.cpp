#include <iostream>
#include <string>

using namespace std;

int main() {
    int quantity;
    cin >> quantity;
    int num;
    char correct;
    for (int i = 0; i < quantity*2; ++i) {
        cin >> num;
        string number = to_string(num);
        if (int(number.length())%2 == 0) {
            if (i%2 == 0) cout << 'B' << endl;
            if (i%2 != 0) cout << 'A' << endl;
            return 0;
        }
        else if (i == 0) correct = number[int(number.length()/2)];
        else if (number[int(number.length()/2)] != correct) {
            if (i%2 == 0) cout << 'B' << endl;
            if (i%2 != 0) cout << 'A' << endl;
            return 0;
        }
    }
    cout << '=' << endl;
    return 0;
}