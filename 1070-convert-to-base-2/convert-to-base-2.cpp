class Solution {
public:
    string baseNeg2(int n) {
        if (n == 0) return "0";

        string res = "";

        while (n != 0) {
            int remainder = n % -2;
            n /= -2;

            if (remainder < 0) {
                remainder += 2;
                n += 1;
            }

            res += to_string(remainder);
        }

        reverse(res.begin(), res.end());
        return res;
    }
};