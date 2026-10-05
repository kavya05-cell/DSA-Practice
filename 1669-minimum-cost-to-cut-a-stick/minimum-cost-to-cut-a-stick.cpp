class Solution {
    int solve(int i, int j, vector<int>& cuts, vector<vector<int>>& dp) {
        if (i + 1 >= j) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        int minCost = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = cuts[j] - cuts[i] + solve(i, k, cuts, dp) + solve(k, j, cuts, dp);
            minCost = min(minCost, cost);
        }
        return dp[i][j] = minCost;
    }
public:
    int minCost(int n, vector<int>& cuts) {
        vector<int> c = cuts;
        c.push_back(0);
        c.push_back(n);
        sort(c.begin(), c.end());
        int m = c.size();
        vector<vector<int>> dp(m, vector<int>(m, -1));
        return solve(0, m - 1, c, dp);
    }
};
