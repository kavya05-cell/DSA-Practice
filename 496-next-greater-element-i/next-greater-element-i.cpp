class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int idx;
        int p;
        vector<int>arr;
        int j=0;
        for(int i=0;i<n;i++){
            p=nums1[i];
            idx=-1;
            for(j=0;j<m;j++){
                if(nums2[j]==p)
                   break;
            }
            for(int k=j+1;k<m;k++){
                if(nums2[k]>p){
                    idx=nums2[k];
                    break;
                }
                
            }
            arr.push_back(idx);
        }
        return arr;
        
    }
};