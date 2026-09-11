class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    int n=intervals.size();
    int news=newInterval[0];
    int newe=newInterval[1];
    vector<vector<int>>res;
    for(int i=0;i<n;i++){
        if(intervals[i][0]>newe){
            res.push_back(newInterval);
            copy(intervals.begin()+i,intervals.end(),back_inserter(res));
            return res;
        }
        else if(intervals[i][1]<news) res.push_back(intervals[i]);
        else{
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=max(newInterval[1],intervals[i][1]);
        }
    }
    res.push_back(newInterval);
    return res;
    }
};