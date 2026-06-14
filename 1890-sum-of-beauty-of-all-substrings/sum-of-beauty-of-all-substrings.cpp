class Solution {
public:
    int beautySum(string s) {
        int n=s.length();
        int sum=0;
        for(int i=0;i<n;i++){
            unordered_map<char,int>freq;
            for(int j=i;j<n;j++){
                freq[s[j]]++;
                int maxx=INT_MIN;
                int minn=INT_MAX;
                for(auto i:freq){
                    minn=min(minn,i.second);
                    maxx=max(maxx,i.second);
                }
                sum+=(maxx-minn);
            }
        }
        return sum;
    }
};