class Solution {
public:
    int climbStairs(int n) {
        if (n<=2) return n;
        int last=1;
        int sdlast=2;
        for(int i=3;i<=n;i++){
            int curr=last+sdlast;
            last=sdlast;
            sdlast=curr;
        }
        return sdlast;

    }
};