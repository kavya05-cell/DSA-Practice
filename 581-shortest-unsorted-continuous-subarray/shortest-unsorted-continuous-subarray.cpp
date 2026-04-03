class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<r && nums[l]<=nums[l+1]){
            l++;
        }
        if(l==n-1){
            return 0;
        }
        while(l<r && nums[r]>=nums[r-1]){
            r--;
        }
        int maxx=nums[l];
        int minn=nums[l];
        for(int k=l;k<=r;k++){
            minn=min(minn,nums[k]);
            maxx=max(maxx,nums[k]);
        }
        while(l>0 && minn<nums[l-1])
              l--;
        while(r<n-1 && nums[r+1]<maxx)
              r++;

        return r-l+1;
    }
};