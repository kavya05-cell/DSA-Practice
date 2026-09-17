class Solution {
public:
    int rob(vector<int>& nums) {
        int r1=0,r2=0;
        for(int i:nums){
            int temp=max(i+r1,r2);
            r1=r2;
            r2=temp;
        }
        return r2;
    }
};