class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        int minn=n/3;
        for(int i=0;i<n;i++){
            int count=0;
            bool flag=false;
            for(int x:ans){
                if(x==nums[i]){
                    flag=true;
                    break;
                }
            }
            if(flag) continue;
            for(int j=i;j<n;j++){
                if(nums[j]==nums[i]){
                    count++;
                }
            }
            if(count>minn){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};