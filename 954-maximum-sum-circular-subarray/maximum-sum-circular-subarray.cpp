class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        vector<int>right(n);
        right[n-1]=nums[n-1];
        int suffix=nums[n-1];
        for(int i=n-2;i>=0;--i){
            suffix+=nums[i];
            right[i]=max(right[i+1],suffix);
        }
        int maxx=nums[0];
        int curr=0;
        int prefix=0;
        for(int i=0;i<n;++i){
            curr=max(curr,0)+nums[i];
            maxx=max(maxx,curr);
            prefix+=nums[i];
            if(i+1<n) maxx=max(maxx,prefix+right[i+1]);
        }
        return maxx;
    }
};