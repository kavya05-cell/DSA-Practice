class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.length();
        vector<int> first(26, -1), last(26, -1);
        
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            if (first[c] == -1) first[c] = i;
            last[c] = i;
        }

        vector<pair<int, int>> intervals;
        for (int i = 0; i < 26; ++i) {
            if (first[i] == -1) continue;

            int left = first[i];
            int right = last[i];
            bool valid = true;

            for (int j = left; j <= right; ++j) {
                int c = s[j] - 'a';
                if (first[c] < left) {
                    valid = false;
                    break;
                }
                right = max(right, last[c]);
            }

            if (valid) {
                intervals.push_back({left, right});
            }
        }
        sort(intervals.begin(), intervals.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        vector<string> result;
        int prev_end = -1;
        for (const auto& [l, r] : intervals) {
            if (l > prev_end) {
                result.push_back(s.substr(l, r - l + 1));
                prev_end = r;
            }
        }

        return result;
    }
};