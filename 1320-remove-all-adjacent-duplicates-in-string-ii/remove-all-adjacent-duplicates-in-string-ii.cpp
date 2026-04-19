class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char,int>> count;
        for(int i=0;i<s.size();i++){
            char curr=s[i];
            if(!count.empty()&& count.back().first==curr){
                count.back().second++;
            }else{
                count.push_back({curr,1});
            }
            if(count.back().second==k) count.pop_back();
        }
        string res="";
        for(int i=0;i<count.size();i++){
            char letter=count[i].first;
            int c=count[i].second;

            res.append(c,letter);
        }
        return res;

    }
};