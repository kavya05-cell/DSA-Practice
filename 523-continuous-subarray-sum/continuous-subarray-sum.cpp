class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>prefix;
        prefix[0]=-1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            int a=sum%k;
            if(a<0) a+=k;
            if(prefix.find(a)!=prefix.end()){
                if(i-prefix[a]>1)
                   return true;
            }
            else
                   prefix[a]=i;
        }
        return false;
    }
};