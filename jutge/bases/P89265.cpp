#include <iostream>
#include <string>

using namespace std;

int main() {
    int inter0, inter1, inter2, inter3;
    cin >> inter0 >> inter1 >> inter2 >> inter3;

    if (inter0 == inter2 && inter1 == inter3) {
        cout << "=";
    }
    else if (inter0 >= inter2 && inter1 <= inter3) {
        cout << "1";
    }
    else if (inter2 >= inter0 && inter3 <= inter1) {
        cout << "2";
    }
    else {
        cout << "?";
    }

    int range0, range1;

    if (inter1 < inter2 || inter0 > inter3) {
        cout << " , [" << "]" << endl;
    }
    else {
        if (inter0 <= inter2) range0 = inter2;
        else range0 = inter0;
        if (inter1 >= inter3) range1 = inter3;
        else range1 = inter1;
        cout << " , [" << range0 << "," << range1 << "]" << endl;
    }

    return 0;
}