class Solution {
public:
vector<vector<int>>res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
            res.clear();
            sort(candidates.begin(),candidates.end());
            vector<int>cur;
            generateSubsets(candidates,target,0,cur,0);
            return res;
        
    }
private:
    void generateSubsets(vector<int>&candidates,int target,int i,vector<int>& cur,int total){
        if(total==target){
            res.push_back(cur);
            return;
        }
        if(total>target || i==candidates.size()) return;
        cur.push_back(candidates[i]);
        generateSubsets(candidates,target,i+1,cur,total+candidates[i]);
        cur.pop_back();
        while(i+1<candidates.size() && candidates[i]==candidates[i+1]) i++;
        generateSubsets(candidates,target,i+1,cur,total);
    }
};