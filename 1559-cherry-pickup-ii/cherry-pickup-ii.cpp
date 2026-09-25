class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int r=grid.size(), c=grid[0].size();
        vector<vector<int>> dp(c, vector<int>(c, -1));
        dp[0][c-1]=grid[0][0]+grid[0][c-1];
        for(int i=1; i<r; ++i){
            vector<vector<int>> next_dp(c, vector<int>(c, -1));
            for(int j1=0; j1<c; ++j1){
                for(int j2=0; j2<c; ++j2){
                    if(dp[j1][j2]==-1) continue;
                    for(int dj1=-1; dj1<=1; ++dj1){
                        for(int dj2=-1; dj2<=1; ++dj2){
                            int nj1=j1+dj1, nj2=j2+dj2;
                            if(nj1>=0 && nj1<c && nj2>=0 && nj2<c){
                                int cherries=(nj1==nj2)?grid[i][nj1]:grid[i][nj1]+grid[i][nj2];
                                next_dp[nj1][nj2]=max(next_dp[nj1][nj2], dp[j1][j2]+cherries);
                            }
                        }
                    }
                }
            }
            dp=move(next_dp);
        }
        int ans=0;
        for(int j1=0; j1<c; ++j1){
            for(int j2=0; j2<c; ++j2){
                ans=max(ans, dp[j1][j2]);
            }
        }
        return ans;
    }
};