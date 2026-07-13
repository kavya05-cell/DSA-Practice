class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>perms={{}};
        for(int num:nums){
            vector<vector<int>>newperms;
            for(const auto& p:perms){
                for(int i=0;i<=p.size();i++){
                    vector<int>pcopy=p;
                    pcopy.insert(pcopy.begin()+i,num);
                    newperms.push_back(pcopy);
                }
            }
            perms=newperms;
        }
        return perms;
    }
};