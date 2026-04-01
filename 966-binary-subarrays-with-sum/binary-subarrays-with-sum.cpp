class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int>prefix;
        int n=nums.size();
        int count=0;
        int cur_sum=0;
        prefix[0]=1;
        for(int i=0;i<n;i++){
            cur_sum+=nums[i];
            if(prefix.find(cur_sum-goal)!=prefix.end())
               count+=prefix[cur_sum-goal];
            prefix[cur_sum]++;
        }
        return count;
    }
};