// Add or remove includes
#include <iostream>
#include <string>

using namespace std;

bool bracketsChecker(string& s, unsigned int& p, int& b) {
    if (b < 0) return false;
    else if (p == s.size() && b == 0) return true;
    else if (p == s.size()) return false;

    if (s[p] == '(') ++b;
    else if (s[p] == ')') --b;

    ++p;

    return bracketsChecker(s, p, b);
}

// Adapt the header of the function to your case
bool wellBracketed(string s) {
    int b = 0;
    unsigned int p = 0;
    return bracketsChecker(s, p, b);
}

// Adapt the call to 'function_name' and the way it is called to your case.
int main()  {
   	string s;
    while (cin >> s)
        cout << wellBracketed(s) << endl;
}
