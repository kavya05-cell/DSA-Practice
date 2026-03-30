class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefix(n,0);
        int l=0,r=0;
        int total=0;
        for(int i=0;i<n;i++){
            total+=nums[i];
        }
        for(int i=0;i<n;i++){
            r=total-l-nums[i];
            if(l==r)
               return i;
            else 
               l+=nums[i];
        }
        return -1;
    }
};