class FreqStack {
    vector<int>st;
    unordered_map<int,int>count;
public:
    FreqStack() {}
    
    void push(int val) {
        st.push_back(val);
        count[val]++;
    }
    
    int pop() {
        int maxx=0;
        for(auto& i:count){
            maxx=max(maxx,i.second);
        }
            int n=st.size()-1;
            while(count[st[n]]!=maxx) n--;
            int  val=st[n];
            st.erase(st.begin()+n);
            count[val]--;
        
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */