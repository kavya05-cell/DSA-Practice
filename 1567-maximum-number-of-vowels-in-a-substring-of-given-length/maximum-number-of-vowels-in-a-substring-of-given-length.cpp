class Solution {
public:
bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    int maxVowels(string s, int k) {
        int maxx=0;
        int n=s.length();
        int start=0;
        int count=0;
        for(int i=0;i<n;i++){
            if(isVowel(s[i]))
               count++;
            // maxx=count;
            if(i-start+1>k){
                if(isVowel(s[start]))
                   count--;
                start++;
            }
            if(i-start+1==k)
               maxx=max(maxx,count);
        }
        return maxx;
    }
};