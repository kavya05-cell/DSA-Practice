class Solution {
public:
    bool backspaceCompare(string s, string t) {
       
    int i = s.length() - 1;
    int j = t.length() - 1;

    int skipS = 0, skipT = 0;

    while(i >= 0 || j >= 0) {

        // process s
        while(i >= 0) {
            if(s[i] == '#') {
                skipS++;
                i--;
            } else if(skipS > 0) {
                skipS--;
                i--;
            } else break;
        }

        // process t
        while(j >= 0) {
            if(t[j] == '#') {
                skipT++;
                j--;
            } else if(skipT > 0) {
                skipT--;
                j--;
            } else break;
        }

        // compare characters
        if(i >= 0 && j >= 0 && s[i] != t[j]) return false;

        // one string ended before other
        if((i >= 0) != (j >= 0)) return false;

        i--;
        j--;
    }

    return true;

    }
};