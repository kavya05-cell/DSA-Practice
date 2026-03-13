class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int min_len=INT_MAX;
        int s=0;
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++){
                sum+=nums[i];
                while(sum>=target){
                    min_len=min(min_len,i-s+1);
                    sum-=nums[s];
                    s++;
                }
        }
        if(min_len==INT_MAX) return 0;
        else return min_len;

    }
};