#include <iostream>
#include <list> 

using namespace std;

void calcMinMax(list<int> &l, int &min, int &max) {
	if (!l.empty()) {
		max = *l.begin();
		min = *l.begin();
		list<int>::const_iterator it;
		for (it = l.begin(); it != l.end(); ++it) {
			if (max < (*it)) max = (*it);
			if (min > (*it)) min = (*it);
		}
	}
}

void removeElement(list<int> &l, int &n, double &t) {
	if (!l.empty()) {
		list<int>::iterator it = l.begin();
		while (it != l.end()) {
			if ((*it) == n) {
				it = l.erase(it);
				t -= n;
				break;
			}
            else ++it;
		}
	}
}

int main() {
	int n1, n2, max=0, min=0;
	double t = 0;
	list<int> l;
	cin >> n1 >> n2;
	while (n1 != 0 && n2 != 0) {
		if (n1 == -1) {
			if (l.empty()) min = max = n2;
			else {
				if (max < n2) max = n2;
				if (min > n2) min = n2;
			}
			l.push_back(n2);
			t += n2;
		}
        else if (n1 == -2) {
			removeElement(l, n2, t);
			if (max == n2 || min == n2) calcMinMax(l, min, max);
		}
		if (!l.empty()) cout << min << ' ' << max << ' ' << t/l.size() << endl;
		else cout << 0 << endl;
		cin >> n1 >> n2;
	}
}
