class Solution {
public:
    string simplifyPath(string path) {
        vector<string> result;
        string temp="";
        int n=path.size();
        for (int i=0;i<=n;i++){
            if(i==n || path[i]=='/'){
                if(temp=="" || temp=="."){

                }
                else if (temp ==".."){
                    if(!result.empty()){
                        result.pop_back();
                    }
                }
                else{
                    result.push_back(temp);
                }
                temp="";
            }
            else{
                temp+=path[i];
            }
        }
        string ans="";
        for(string i:result){
            ans+="/"+i;
        }
        if(ans.empty())
           return "/";
        else
           return ans;
    }
};