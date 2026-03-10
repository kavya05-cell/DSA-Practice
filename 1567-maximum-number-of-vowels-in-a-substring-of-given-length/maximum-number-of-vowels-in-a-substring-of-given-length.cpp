class Solution {
public:
bool isVowel(char c){
    return c=='a' || c=='e' || c=='i' || c=='o' || c=='u';
}
    int maxVowels(string s, int k) {
        int maxx=0;
        int n=s.length();
        int count=0;
        for(int i=0;i<k;i++){
            if(isVowel(s[i])) 
               count++;
        }
        maxx=count;
        for(int i=k;i<n;i++){
            
            if(isVowel(s[i-k]))
               count--;
            if(isVowel(s[i]))
               count++;
            if(count>maxx)
              maxx=count;
        }
        return maxx;
    }
};