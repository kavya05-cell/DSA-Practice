#include <string>

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        std::sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });
        unordered_map<string, int> dp;
        int maxLen = 1;
        for (const string& word : words) {
            int currentMax = 1;
            for (size_t i = 0; i < word.size(); ++i) {
                string predecessor = word.substr(0, i) + word.substr(i + 1);
                if (dp.count(predecessor)) {
                    currentMax = max(currentMax, dp[predecessor] + 1);
                }
            }
            dp[word] = currentMax;
            maxLen = max(maxLen, currentMax);
        }
        return maxLen;
    }
};