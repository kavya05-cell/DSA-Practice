class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {};

        unordered_map<string, int> dist;
        queue<string> q;
        
        q.push(beginWord);
        dist[beginWord] = 0;
        dict.erase(beginWord);

        // Phase 1: BFS to find shortest distance to all reachable words
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr == endWord) break;

            int steps = dist[curr];
            string temp = curr;
            for (int i = 0; i < temp.size(); i++) {
                char orig = temp[i];
                for (char c = 'a'; c <= 'z'; c++) {
                    temp[i] = c;
                    if (dict.count(temp)) {
                        dict.erase(temp);
                        dist[temp] = steps + 1;
                        q.push(temp);
                    }
                }
                temp[i] = orig;
            }
        }

        if (!dist.count(endWord)) return {};

        // Phase 2: DFS backwards from endWord to beginWord
        vector<vector<string>> ans;
        vector<string> path = {endWord};
        dfs(endWord, beginWord, dist, path, ans);
        return ans;
    }

private:
    void dfs(const string& curr, const string& beginWord, unordered_map<string, int>& dist,
             vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }

        int targetDist = dist[curr] - 1;
        string temp = curr;
        for (int i = 0; i < temp.size(); i++) {
            char orig = temp[i];
            for (char c = 'a'; c <= 'z'; c++) {
                temp[i] = c;
                if (dist.count(temp) && dist[temp] == targetDist) {
                    path.push_back(temp);
                    dfs(temp, beginWord, dist, path, ans);
                    path.pop_back();
                }
            }
            temp[i] = orig;
        }
    }
};