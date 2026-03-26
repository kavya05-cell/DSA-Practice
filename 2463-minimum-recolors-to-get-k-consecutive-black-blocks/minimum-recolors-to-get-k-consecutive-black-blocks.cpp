class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.length();
        int minn=n;
        for(int i=0;i<=n-k;i++){
            int count=0;
            for(int j=i;j<i+k;j++){
               if(blocks[j]=='W')
                  count++;
            }
            minn=min(minn,count);
        }
        return minn;
    }
};