class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        unordered_map<int,int>lm;
        unordered_map<int,int>rm;
        lm[0]=height[0];
        rm[0]=height[n-1];
        for(int i=1;i<n;i++)
            lm[i]=max(lm[i-1],height[i]);
        for(int i=n-1;i>0;i--)
            rm[i]=max(rm[i+1],height[i]);
        for(int i=0;i<n;i++)
            water+=max(0,min(lm[i],rm[i])-height[i]);
        return water;
    }
};