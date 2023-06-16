class Solution {
public:
    int productOfDigits(int n) {
        int res = 1;
        while (n > 0) {
            res *= n % 10;
            n /= 10;
        }
        return res;
    }

    int sumOfDigits(int n) {
        int res = 0;
        while (n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int subtractProductAndSum(int n) {
        int n1 = productOfDigits(n);
        int n2 = sumOfDigits(n);
        return n1 - n2;
    }
};