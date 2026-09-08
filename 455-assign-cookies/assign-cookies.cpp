class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
       int gidx=0;
       int sidx=0;
       while(gidx<g.size() && sidx<s.size()){
        if(s[sidx]>=g[gidx]) gidx++;
        sidx++;
       }
       return gidx;
    }
};