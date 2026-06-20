class Solution {
public:
    int findMin(vector<int>& nums) {
        int minn=INT_MAX;
        for(int i:nums){
            if(i<minn) minn=i;
        }
        return minn;
    }
};