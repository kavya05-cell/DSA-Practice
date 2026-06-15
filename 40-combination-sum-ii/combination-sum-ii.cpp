class Solution {
public:
    void findc(int idx, int k, vector<int>&arr,vector<vector<int>>&ans,vector<int>&ds){
        if(k==0){
            ans.push_back(ds);
            return;
        }
        for(int i=idx;i<arr.size();i++){
            if(i>idx && arr[i]==arr[i-1]) continue;
            if(arr[i]>k) break;
            ds.push_back(arr[i]);
            findc(i+1,k-arr[i],arr,ans,ds);
            ds.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>ds;
        findc(0,target,candidates,ans,ds);
        return ans;
    }
};