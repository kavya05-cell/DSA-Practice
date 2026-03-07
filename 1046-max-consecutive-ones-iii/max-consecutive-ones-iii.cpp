class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int m=0;
        int z=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0) z+=1;
            while(z>k){
                if(nums[l]==0) z-=1;
                l+=1;
                  
            }
            m=max(m,i-l+1);
        }
        return m;
    }
};