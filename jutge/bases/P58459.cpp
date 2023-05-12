#include <iostream>

using namespace std;

bool is_leap_year(int year) {
	return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

bool is_valid_date(int d, int m, int y) {
	int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	if (is_leap_year(y)) daysInMonth[1] = 29;
	if (m < 1 || m > 12) return false;
	if (d < 1 || d > daysInMonth[m - 1]) return false;
	return true;
}

int main() {
	int d, m, y;
	cin >> d >> m >> y;
	cout << is_valid_date(d, m, y) << endl;
	return 0;
}