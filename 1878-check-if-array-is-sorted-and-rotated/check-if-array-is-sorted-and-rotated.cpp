class Solution {
public:
    bool check(vector<int>& nums) {
        int count=0;
        int p=nums.size();

        if(nums[0]<nums[p-1]){
            count++;
        }

        for(int i=0; i<p-1;i++){
            if (nums[i]>nums[i+1]){
                 count++;
            }
        }
        if (count>1){
            return false;
        }
        return true;
       
    }
};