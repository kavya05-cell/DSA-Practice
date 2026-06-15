class Solution {
public:
void finds(int idx, vector<int>&nums, vector<int>&ds, set<vector<int>>&res){
    if(idx==nums.size()){
        res.insert(ds);
        return;
    }
    ds.push_back(nums[idx]);
    finds(idx+1,nums,ds,res);
    ds.pop_back();
    finds(idx+1,nums,ds,res);
}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>res;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        finds(0,nums,ds,res);
        vector<vector<int>>ans(res.begin(),res.end());
        return ans;
    }
};