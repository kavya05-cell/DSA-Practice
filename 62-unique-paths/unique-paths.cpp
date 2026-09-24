class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>row(n,1);
        for(int i=0;i<m-1;++i){
            vector<int>newr(n,1);
            for(int j=n-2;j>=0;--j) 
                newr[j]=newr[j+1]+row[j];
            row=newr;
        }
        return row[0];
    }
};