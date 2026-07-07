class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()%groupSize!=0) return false;
        map<int,int>freq;
        for(int card:hand) freq[card]++;
        auto i=freq.begin();
        while(i!=freq.end()){
            if(i->second==0){
                ++i;
                continue;
            }
            int s=i->first;
            int count=i->second;
            for(int i=0;i<groupSize;i++){
                if(freq[s+i]<count) return false;
                freq[s+i]-=count;
            }
            ++i;
        }
        return true;
    }
};