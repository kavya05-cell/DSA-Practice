class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>arr;
        for(int i=0;i<n;i++){
            if(arr.find(nums[i])!=arr.end() && (i-arr[nums[i]])<=k) return true;
            arr[nums[i]]=i;
        }
        return false;
    }
};