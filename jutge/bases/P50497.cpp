#include <string>

using namespace std;

bool is_palindrome(const string& s) {
    int stringLength = (int)s.length();
    for (int i = 0; i < (int)(s.length()/2); ++i) {
        if (s[i] != s[stringLength-i-1]) {
            return false;
        }
    }

    return true;
}

int main() {
    return 0;
}