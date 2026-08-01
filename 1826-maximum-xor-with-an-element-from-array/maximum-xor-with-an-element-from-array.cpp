class Solution {
private:
    struct TrieNode {
        TrieNode* children[2] = {nullptr, nullptr};
    };

    TrieNode* root = new TrieNode();

    void insert(int num) {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->children[bit]) {
                node->children[bit] = new TrieNode();
            }
            node = node->children[bit];
        }
    }

    int getMaxXor(int num) {
        TrieNode* node = root;
        int maxXor = 0;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int desiredBit = 1 - bit;
            
            if (node->children[desiredBit]) {
                maxXor |= (1 << i);
                node = node->children[desiredBit];
            } else {
                node = node->children[bit];
            }
        }
        return maxXor;
    }

public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());

        int qLen = queries.size();
        // Stores {m_i, x_i, original_index}
        vector<vector<int>> offlineQueries(qLen);
        for (int i = 0; i < qLen; i++) {
            offlineQueries[i] = {queries[i][1], queries[i][0], i};
        }
        sort(offlineQueries.begin(), offlineQueries.end());

        vector<int> ans(qLen);
        int numsIdx = 0;
        int n = nums.size();

        for (const auto& q : offlineQueries) {
            int m = q[0];
            int x = q[1];
            int idx = q[2];

            while (numsIdx < n && nums[numsIdx] <= m) {
                insert(nums[numsIdx]);
                numsIdx++;
            }

            if (numsIdx == 0) {
                ans[idx] = -1;
            } else {
                ans[idx] = getMaxXor(x);
            }
        }

        return ans;
    }
};