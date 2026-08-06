class Solution {
public:
    int digitProduct(int n) {
        int prod = 1;
        while (n > 0) {
            prod *= (n % 10);
            n /= 10;
        }
        return prod;
    }

    int smallestNumber(int n, int t) {
        while (digitProduct(n) % t != 0) {
            n++;
        }
        return n;
    }
};