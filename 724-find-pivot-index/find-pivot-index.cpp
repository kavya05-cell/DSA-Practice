class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int lsum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }   
        for(int i=0;i<n;i++){
            int tsum=sum-lsum-nums[i];
            if(lsum==tsum)
               return i;
            else
               lsum+=nums[i];
        }
        return -1;
    }
};