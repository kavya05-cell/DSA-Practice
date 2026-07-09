class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<int>count={a,b,c};
        string res;
        int repeat=-1;
        while(true){
            int maxchar=getMax(count,repeat);
            if(maxchar==-1) break;
            res+=(char)(maxchar+'a');
            count[maxchar]--;
            if(res.size()>1 && res.back()==res[res.size()-2]) repeat=maxchar;
            else repeat=-1;
        }
        return res;
    }
private:
int getMax(const vector<int>& count,int repeat){
    int idx=-1,maxc=0;
    for(int i=0;i<3;i++){
        if(i==repeat || count[i]==0) continue;
        if(maxc<count[i]){
            maxc=count[i];
            idx=i;
        }
    }
    return idx;
}
};