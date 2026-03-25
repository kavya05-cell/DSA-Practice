class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        vector<int>arr;
        while(i<n){
            int j=nums[i]-1;
            if(nums[i]!=nums[j])
               swap(nums[i],nums[j]);
            else
               i++;
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1)
               return {nums[i],i+1};
        }
        return arr;
    }
};