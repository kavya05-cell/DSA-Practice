class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>avai;
        priority_queue<array<int,3>,vector<array<int,3>>,greater<>>pend;
        int n=tasks.size();
        for(int i=0;i<n;++i){
            pend.push({tasks[i][0],tasks[i][1],i});
        }
        vector<int>res;
        long long time=0;
        while(!pend.empty() || !avai.empty()){
            while(!pend.empty() && pend.top()[0]<=time){
                auto[enqueueTime,processTime,idx]=pend.top();
                pend.pop();
                avai.push({processTime,idx});
            }
            if(avai.empty()){
                time=pend.top()[0];
                continue;
            }
            auto[processTime,idx]=avai.top();
            avai.pop();
            time+=processTime;
            res.push_back(idx);
        }
        return res;
    }
};