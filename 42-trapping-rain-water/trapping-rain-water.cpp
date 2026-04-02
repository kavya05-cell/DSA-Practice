class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0;
        unordered_map<int,int>lm;
        unordered_map<int,int>rm;
        lm[0]=height[0];
        rm[n-1]=height[n-1];
        for(int i=1;i<n;i++)
            lm[i]=max(lm[i-1],height[i]);
        for(int i=n-2;i>=0;i--)
            rm[i]=max(rm[i+1],height[i]);
        for(int i=0;i<n;i++)
            water+=(min(lm[i],rm[i])-height[i]);
        return water;
    }
};