#include <vector>
#include <algorithm>
#include <climits>
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy1 = INT_MAX, buy2 = INT_MAX;
        int prof1 = 0, prof2 = 0;
        for (int price : prices) {
            buy1 = min(buy1, price);
            prof1 = max(prof1, price - buy1);
            buy2 = min(buy2, price - prof1);
            prof2 = max(prof2, price - buy2);
        }
        return prof2;
    }
};