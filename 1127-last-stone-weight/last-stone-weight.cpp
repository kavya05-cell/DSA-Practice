class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int>arr;
       for(int s:stones) arr.push(s);
       while(arr.size()>1){
        int first=arr.top();
        arr.pop();
        int sec=arr.top();
        arr.pop();
        if(sec<first) arr.push(first-sec);
       }
       arr.push(0);
       return arr.top();
    }
};