class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>>res;
        for(int i=0;i< (1<<n); ++i){
            vector<int>comb;
            for(int j=0;j<n;++j){
                if(i & (1<<j)) comb.push_back(j+1);
            }
            if(comb.size()==k) res.push_back(comb);
        }
        return res;
    }
};