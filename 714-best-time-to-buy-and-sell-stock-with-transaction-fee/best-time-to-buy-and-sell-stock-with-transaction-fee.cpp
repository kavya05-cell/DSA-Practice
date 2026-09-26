#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    long long solve(int day, int canBuy,vector<int>& prices,int fee,vector<vector<long long>>& dp) {
        int n = prices.size();
        if (day == n) return 0;
        if (dp[day][canBuy] != -1) return dp[day][canBuy];
        long long bestProfit;
        if (canBuy == 1) {
            long long buy = -prices[day] + solve(day + 1, 0, prices, fee, dp);
            long long skip = solve(day + 1, 1, prices, fee, dp);
            bestProfit = max(buy, skip);
        } else {
            long long sell = prices[day] - fee+ solve(day + 1, 1, prices, fee, dp);
            long long hold = solve(day + 1, 0, prices, fee, dp);
            bestProfit = max(sell, hold);
        }
        dp[day][canBuy] = bestProfit;
        return dp[day][canBuy];
    }

public:
    long long maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(0, 1, prices, fee, dp);
    }
};