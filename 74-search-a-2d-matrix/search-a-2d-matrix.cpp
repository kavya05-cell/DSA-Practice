class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        int i=0,j=rows-1;
        while(i<=j){
            int row=(i+j)/2;
            if(target>matrix[row][cols-1]) i=row+1;
            else if(target<matrix[row][0]) j=row-1;
            else break;
        }
        if(!(i<=j)) return false;
        int row=(i+j)/2;
        int l=0,r=cols-1;
        while(l<=r){
            int m=(l+r)/2;
            if(target>matrix[row][m]) l=m+1;
            else if(target<matrix[row][m]) r=m-1;
            else return true;
        }
        return false;
    }
};