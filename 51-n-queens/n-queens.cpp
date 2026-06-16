class Solution {
public:
void solve(int col,vector<string>&board,int n, vector<int>&left,vector<int>&upper, vector<int>&lower, vector<vector<string>>&ans){
    if(col==n){
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++){
        if(left[row]==0  & lower[row+col]==0 && upper[n-1+row-col]==0){
            board[row][col]='Q';
            left[row]=1;
            lower[row+col]=1;
            upper[n-1+row-col]=1;
            solve(col+1,board,n,left,upper,lower,ans);
            board[row][col]='.';
            left[row]=0;
            lower[row+col]=0;
            upper[n-1+row-col]=0;
        }
    }
}
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        vector<int>left(n,0),upper(2*n-1,0),lower(2*n-1,0);
        solve(0,board,n,left,upper,lower, ans);
        return ans;
    }
};