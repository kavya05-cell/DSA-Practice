class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int minn=n/3+1;
        unordered_map<int,int>count;
        for(int i=0;i<n;i++){
            count[nums[i]]++;
            if(count[nums[i]]==minn){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};