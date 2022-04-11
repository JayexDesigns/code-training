using namespace std;

void decompose(int n, int& h, int& m, int& s) {
    s = n % 60;
    m = (int)(n - s) / 60;
    h = (int)(m - m % 60) / 60;
    m = m % 60;
}

int main() {
    return 0;
}