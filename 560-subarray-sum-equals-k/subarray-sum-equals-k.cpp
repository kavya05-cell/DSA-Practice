class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>prefix;
        int n=nums.size();
        int count=0;
        int cur_sum=0;
        prefix[0]=1;
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            if(prefix.find(cur_sum-k)!=prefix.end())
               count+=prefix[cur_sum-k];
            prefix[cur_sum]++;
        }
        return count;
    }
};