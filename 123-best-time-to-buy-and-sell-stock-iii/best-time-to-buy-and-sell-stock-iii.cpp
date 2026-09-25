#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> next(2, vector<int>(3, 0));
        for (int index = n - 1; index >= 0; index--) {
            vector<vector<int>> curr(2, vector<int>(3, 0));
            for (int rem= 1;rem<= 2;rem++) {
                int buy = -prices[index]+ next[0][rem];
                int skip = next[1][rem];
                curr[1][rem] = max(buy, skip);
                int sell = prices[index]+ next[1][rem- 1];
                int hold = next[0][rem];
                curr[0][rem] = max(sell, hold);
            }
            next = curr;
        }
        return next[1][2];
    }
};