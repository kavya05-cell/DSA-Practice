class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int left,right;
        int sum=0;
        int summ=nums[0]+nums[1]+nums[2];
        for(int i=0;i<n;i++){
            left=i+1;
            right=n-1;
            while(left<right){
            sum=nums[i]+nums[left]+nums[right];
            if(abs(target-sum)<abs(target-summ)){
                summ=sum;
            }
            if(sum<target){
                left++;
            }
            else if(sum>target){
                right--;
            }
            else{
                return sum;
            }
            }
        }
        return summ;
    }
};