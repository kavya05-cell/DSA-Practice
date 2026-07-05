class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>count(26,0);
        for(char task:tasks){
            count[task-'A']++;
        }
        int maxx=*max_element(count.begin(),count.end());
        int mc=0;
        for(int i:count){
            if(i==maxx) mc++;
        }
        int time=(maxx-1)*(n+1)+mc;
        return max((int)tasks.size(),time);
    }
};