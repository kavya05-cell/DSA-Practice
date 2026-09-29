class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string r = s;
        reverse(r.begin(), r.end());
        vector<int> dp(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            int prev = 0;
            for (int j = 1; j <= n; ++j) {
                int temp = dp[j];
                if (s[i - 1] == r[j - 1]) dp[j] = prev + 1;
                else dp[j]=max(dp[j], dp[j - 1]);
                prev = temp;
            }
        }
        return n - dp[n];
    }
};