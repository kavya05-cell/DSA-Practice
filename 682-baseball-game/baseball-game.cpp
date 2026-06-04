class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int>rec;
        for(const string& op:operations){
            if(op=="+"){
            int n=rec.size();
            rec.push_back(rec[n-1]+rec[n-2]);
            }
        else if(op=="D")
            rec.push_back(2*rec.back());
        else if(op=="C")
            rec.pop_back();
        else
            rec.push_back(stoi(op));
    }
    int total=0;
    for(int i:rec) total+=i;
    return total;
    }
};