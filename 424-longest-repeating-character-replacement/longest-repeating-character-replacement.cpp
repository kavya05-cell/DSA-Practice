class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        int maxx=0;
        int maxf=0;
        unordered_map<char,int>count;
        int l=0;
        for(int i=0;i<n;i++){
            count[s[i]]++;
            maxf=max(maxf,count[s[i]]);
            while((i-l+1)-maxf>k){
                count[s[l]]--;
                l++;
            }
            maxx=max(maxx,i-l+1);
        }
        return maxx;
    }
};