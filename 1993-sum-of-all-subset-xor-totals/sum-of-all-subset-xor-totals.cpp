class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int res=0;
        vector<int>arr;
        function<void(int)>backtrack=[&](int i){
            int xorr=0;
            for(int num:arr) xorr^=num;
            res+= xorr;for(int j=i;j<nums.size();++j){
                arr.push_back(nums[j]);
                backtrack(j+1);
                arr.pop_back();
            }
        };
        backtrack(0);
        return res;
    }
};