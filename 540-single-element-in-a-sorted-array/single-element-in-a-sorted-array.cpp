class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>arr;
        for(int i=0;i<n;i++){
            arr[nums[i]]++;
        }
        for(auto i:arr){
            if(i.second==1){
                return i.first;
            }
        }
        return 0;
    }
};