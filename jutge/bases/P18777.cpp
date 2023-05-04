#include <iostream>
#include <cmath>

using namespace std;

string day_of_the_week (int d, int m, int y) {
	int m2 = m, y2 = y;
	m2 -= 2;
	if (m2 <= 0) {
		m2 += 12;
		y2 -= 1;
	}
	int c = y2 / 100;
	int a = ((y2 % 100) + 100) % 100;
	int f = floor(2.6 * m2 - 0.2) + d + a + floor(a / 4) + floor(c / 4) - 2 * c;
	string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	return days[((f % 7) + 7) % 7];
}

int main() {
	int d, m, y;
	cin >> d >> m >> y;
	cout << day_of_the_week(d, m, y) << endl;
	return 0;
}
