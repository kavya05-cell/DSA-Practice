class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>dstack;
        unordered_map<int,int> mp;
        int n=nums1.size();
        int m=nums2.size();
        vector<int>arr;
        for(int i=0;i<m;i++){
            while(!dstack.empty() && dstack.top()<nums2[i]){
                mp[dstack.top()]=nums2[i];
                dstack.pop();
            }
            dstack.push(nums2[i]);
        }
        // remaining elements
         while(!dstack.empty()){
            mp[dstack.top()]=-1;
            dstack.pop();
        }
        for(int i=0;i<n;i++)
            arr.push_back(mp[nums1[i]]);

        
        return arr;

    }
};