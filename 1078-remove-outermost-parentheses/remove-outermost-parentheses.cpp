class Solution {
public:
    string removeOuterParentheses(string s) {
        string res="";
        int count=0;
        for(char ch:s){
            if(ch=='('){
                if(count>0) res+=ch;
                count++;
            }
            else if(ch==')'){
                count--;
                if(count>0) res+=ch;
            }
        }
        return res;
    }
};