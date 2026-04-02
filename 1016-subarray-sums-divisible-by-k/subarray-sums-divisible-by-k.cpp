class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        unordered_map<int,int>prefix;
        prefix[0]=1;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int a=sum%k;
            if(a<0)
               a+=k;
            count+= prefix[a];
            prefix[a]++;
               
        }
        return count;
    }
};