class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int maxx=INT_MIN;
        int sum=0;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           maxx=max(maxx,sum);
           if(sum<0)
              sum=0;
        }
        return maxx;
    }
};