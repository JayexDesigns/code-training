#include <iostream>
#include <string>
#include <vector>

using namespace std;

string invertNumbers(vector<int> numbers) {
    string newNumbers = "";
    for (int i = 0; i < (int)numbers.size(); ++i) {
        if (i != 0) {
            newNumbers += " ";
        }
        newNumbers += to_string(numbers[(int)numbers.size() - i - 1]);
    }

    return newNumbers;
}

int main() {
    int quantity;
    while (cin >> quantity) {
        vector<int> numbers;
        int num;
        for (int i = 0; i < quantity; ++i) {
            cin >> num;
            numbers.push_back(num);
        }

        cout << invertNumbers(numbers) << endl;
    }

    return 0;
}