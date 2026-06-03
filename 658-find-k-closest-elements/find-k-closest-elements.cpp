class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>diff;
        for(int a:arr){
            diff.push_back({abs(a-x),a});
        }
        sort(diff.begin(),diff.end());
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(diff[i].second);
        }
        sort(res.begin(),res.end());
        return res;
    }
};