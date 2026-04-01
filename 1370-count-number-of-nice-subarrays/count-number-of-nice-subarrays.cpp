class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                nums[i]=0;
            else
                nums[i]=1;
        }
        int count=0;
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(prefix.find(sum-k)!=prefix.end())
               count+=prefix[sum-k];
            prefix[sum]++;
            
        }
        return count;
    }
};