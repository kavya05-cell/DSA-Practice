class StockSpanner {
    vector<int>arr;
public:
    StockSpanner() {}  
    
    int next(int price) {
        arr.push_back(price);
        int n=arr.size()-2;
        while(n>=0 && arr[n]<=price) n--;
        return arr.size()-n-1;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */