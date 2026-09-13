class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int s=n-1,e=0;
        int tank=gas[s]-cost[s];
        while(s>e){
            if(tank<0){
                s--;
                tank+=gas[s]-cost[s];
            }
            else{
                tank+=gas[e]-cost[e];
                e++;
            }
        }
        return tank >=0 ? s : -1;
    }
};