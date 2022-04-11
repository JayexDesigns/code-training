#include <iostream>

using namespace std;

int main() {
    int temperature;
    cin >> temperature;
    if (temperature < 10) {
        cout << "it's cold" << endl;
        if (temperature <= 0) cout << "water would freeze" << endl;
    }
    else if (temperature > 30) {
        cout << "it's hot" << endl;
        if (temperature >= 100) cout << "water would boil" << endl;
    }
    else cout << "it's ok" << endl;
    return 0;
}