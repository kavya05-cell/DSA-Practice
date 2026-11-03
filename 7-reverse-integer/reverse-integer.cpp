class Solution {
public:
    int reverse(int x) {
        long long val=x;
        long res = rec(abs(val), 0) * (val < 0 ? -1 : 1);
        if (res < INT_MIN || res > INT_MAX) {
            return 0;
        }
        return (int)res;
    }

private:
    long rec(long long n, long rev) {
        if (n == 0) return rev;
        rev = rev * 10 + n % 10;
        return rec(n / 10, rev);
    }
};