class KthLargest {
public:
priority_queue<int,vector<int>,greater<int>>arr;
int k;
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for(int num:nums){
            arr.push(num);
            if(arr.size()>k) arr.pop();
        }
    }
    
    int add(int val) {
        arr.push(val);
        if(arr.size()>k) arr.pop();
        return arr.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */