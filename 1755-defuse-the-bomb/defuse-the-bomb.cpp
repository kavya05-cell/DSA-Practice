class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n=code.size();
        int s,e;
        int sum=0;
        vector<int>arr(n,0);
        if(k==0) return arr;;
        if(k>0){
            s=1;
            e=k;
        }
        else{
            s=n+k;
            e=n-1;
        }
        for(int i=s;i<=e;i++){
            sum+=code[i%n];
        }
        for(int i=0;i<n;i++){
            arr[i]=sum;
            sum-=code[s%n];
            sum+=code[(e+1)%n];
            s++;
            e++;
            
        }
        return arr;
    }
};