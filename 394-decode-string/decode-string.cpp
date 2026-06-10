class Solution {
public:
    string decodeString(string s) {
        string result="";
        for(char c:s) {
            if (c!=']') {
                result.push_back(c);
            } else {
                string current_str="";
                while (!result.empty() && result.back()!='[') {
                    current_str=result.back()+current_str;
                    result.pop_back();
                }
                if (!result.empty() && result.back()=='[') {
                    result.pop_back();
                }
                string number_str="";
                while(!result.empty() && isdigit(result.back())) {
                    number_str=result.back()+number_str;
                    result.pop_back();
                }
                int k=stoi(number_str);
                while(k--){
                    result+=current_str;
                }
            }
        }
        return result;
    }
};