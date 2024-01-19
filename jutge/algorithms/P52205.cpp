#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<double> &v, int left, int mid, int right) {
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<double> L(n1), R(n2);

	for (int i = 0; i < n1; ++i) L[i] = v[left + i];
	for (int j = 0; j < n2; ++j) R[j] = v[mid + 1 + j];

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2) {
		if (L[i] <= R[j]) {
			v[k] = L[i];
			++i;
		}
		else {
			v[k] = R[j];
			++j;
		}
		++k;
	}

	while (i < n1) {
		v[k] = L[i];
		++i;
		++k;
	}

	while (j < n2) {
		v[k] = R[j];
		++j;
		++k;
	}
}

void mergeSortHelper(vector<double> &v, int left, int right){
	if (left < right) {
		int mid = left + (right - left) / 2;

		mergeSortHelper(v, left, mid);
		mergeSortHelper(v, mid + 1, right);

		merge(v, left, mid, right);
	}
}

void mergesort(vector<double> &v) {
	if (v.empty()) return;
	int size = v.size();
	mergeSortHelper(v, 0, size - 1);
}

int main() {
	cout << fixed << setprecision(1);
	int n;
	while (cin >> n) {
		vector<double> v(n);
		for (int i = 0; i < n; ++i) {
			cin >> v[i];
		}
		mergesort(v);
		for (int i = 0; i < n; ++i) {
			cout << " " << v[i];
		}
		cout << endl;
	}
	return 0;
}
