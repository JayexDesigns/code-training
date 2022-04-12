#include <iostream>
#include <vector>

using namespace std;

int main() {
    int quantity;
    cin >> quantity;
    vector<int> numbers;
    int num;
    for (int i = 0; i < quantity; ++i) {
        cin >> num;
        numbers.push_back(num);
    }

    int lastNum = numbers[quantity-1];
    int times = 0;
    for (int i = 0; i < quantity-1; ++i) {
        if (lastNum == numbers[i]) times++;
    }

    cout << times << endl;

    return 0;
}