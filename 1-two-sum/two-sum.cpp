class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>arr;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int rem=target-nums[i];
            if(arr.find(rem)!=arr.end()){
                return {i,arr[rem]};
            }
            arr[nums[i]]=i;
        }
        return {};
    }
};