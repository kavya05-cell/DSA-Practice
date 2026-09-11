class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        res.push_back(intervals[0]);
        for(auto& i:intervals){
            int s=i[0];
            int e=i[1];
            int le=res.back()[1];
            if(s<=le) res.back()[1]=max(le,e);
            else res.push_back({s,e});
        }
        return res;
    }
};