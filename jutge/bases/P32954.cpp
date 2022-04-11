void sort3(int& a, int& b, int& c) {
    if (a > b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    if (c < a) {
        a = a + c;
        c = a - c;
        a = a - c;
        b = b + c;
        c = b - c;
        b = b - c;
    }
    else if (c < b) {
        b = b + c;
        c = b - c;
        b = b - c;
    }
}

int main() {
    return 0;
}