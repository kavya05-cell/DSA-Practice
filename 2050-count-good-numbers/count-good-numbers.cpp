class Solution {
    private:
    long long MOD=1e9+7;
    long long good(long long base, long long exp){
        long long ans=1;
        base=base%MOD;
        while(exp>0){
            if(exp%2==1) 
               ans=(ans*base)%MOD;
            base=(base*base)%MOD;
            exp/=2;
        }
        return ans;
    }
public:
int countGoodNumbers(long long n){
    long long odd=n/2;
    long long even=n-odd;
    long long eways=good(5,even);
    long long oways=good(4,odd);
    return (eways*oways)%MOD;
}
};