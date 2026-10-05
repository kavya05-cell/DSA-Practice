class Solution {
    bool parse(const string& s, int& i) {
        char ch = s[i++];
        if (ch == 't') return true;
        if (ch == 'f') return false;
        
        i++; // skip '('
        if (ch == '!') {
            bool res = !parse(s, i);
            i++; // skip ')'
            return res;
        }
        
        bool isAnd = (ch == '&');
        bool res = isAnd;
        
        while (s[i] != ')') {
            bool val = parse(s, i);
            if (isAnd) res = res && val;
            else res = res || val;
            
            if (s[i] == ',') i++;
        }
        i++; // skip ')'
        return res;
    }

public:
    bool parseBoolExpr(string expression) {
        int i = 0;
        return parse(expression, i);
    }
};