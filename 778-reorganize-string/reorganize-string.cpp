class Solution {
public:
    string reorganizeString(string s) {
        vector<int>freq(26,0);
        for(char c:s) freq[c-'a']++;
        int maxfreq=*max_element(freq.begin(),freq.end());
        if(maxfreq>(s.size()+1)/2) return "";
        string res;
        while(res.size()<s.size()){
            int maxidx=findMaxIndex(freq);
            char maxchar='a'+maxidx;
            res+=maxchar; 
            freq[maxidx]--;
            if(freq[maxidx]==0) continue;
            int temp=freq[maxidx];
            freq[maxidx]=INT_MIN;
            int nextidx=findMaxIndex(freq);
            char nextchar='a'+nextidx;
            res+=nextchar;
            freq[maxidx]=temp;
            freq[nextidx]--;
        }
        return res;
    }
    private:
    int findMaxIndex(const vector<int>&freq){
        int maxidx=0;
        for(int i=1;i<freq.size();i++){
            if(freq[i]>freq[maxidx]) maxidx=i;
        }
        return maxidx;
    }
};