#include <bits/stdc++.h>
using namespace std;
class Solution {
private:
    int solve(int day,int canBuy,int rem,vector<int>& prices,vector<vector<vector<int>>>& dp) {
        int n = prices.size();
        if (day == n || rem== 0) return 0;
        if (dp[day][canBuy][rem] != -1) 
            return dp[day][canBuy][rem];
        if (canBuy == 1) {
            int buyP= -prices[day] + solve(day + 1,0,rem,prices,dp);
            int skipP= solve(day + 1,1,rem,prices,dp);
            dp[day][canBuy][rem] = max(buyP,skipP);
            return dp[day][canBuy][rem];
        }
        int sellP= prices[day] + solve(day + 1,1,rem-1,prices,dp);
        int holdP= solve(day + 1,0,rem,prices,dp);
        dp[day][canBuy][rem] = max(sellP,holdP);
        return dp[day][canBuy][rem];
    }
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(k + 1, -1)));
        return solve(0, 1, k, prices, dp);
    }
};