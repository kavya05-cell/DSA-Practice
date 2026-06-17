class Solution {
public:
bool isvalid(vector<vector<char>> &board,int row,int col, char c){
    for(int i=0;i<9;i++){
        if(board[i][col]==c) return false;
        if(board[row][i]==c) return false;
    }
    int rows=3*(row/3);
    int cols=3*(col/3);
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[rows+i][cols+j]==c) return false;
        }
    }
    return true;
}
    bool solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(isvalid(board,i,j,c)){
                            board[i][j]=c;
                            if(solveSudoku(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};