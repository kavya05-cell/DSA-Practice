class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int r=1;r<n;++r){
            for(int c=0;c<n;++c){
                int minAbove=matrix[r-1][c];
                if(c>0) minAbove=min(minAbove,matrix[r-1][c-1]);
                if(c<n-1) minAbove=min(minAbove,matrix[r-1][c+1]);
                matrix[r][c]+=minAbove;
            }
        }
        int ans=matrix[n-1][0];
        for(int c=1;c<n;++c){
            ans=min(ans,matrix[n-1][c]);
        }
        return ans;
    }
};