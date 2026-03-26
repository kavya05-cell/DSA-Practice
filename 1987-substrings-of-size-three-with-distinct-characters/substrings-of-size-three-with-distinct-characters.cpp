class Solution {
public:
    int countGoodSubstrings(string s) {
        int n=s.length();
        int count=0;
        for(int i=0;i<=n-3;i++){
            vector<int>arr(26,0);
            bool a=true;
            for(int j=i;j<i+3;j++){
                arr[s[j]-'a']++;
                if(arr[s[j]-'a']>1){
                    a=false;
                    break;
                }
            }
            if(a)
               count++;
        }
        return count;
    }
};