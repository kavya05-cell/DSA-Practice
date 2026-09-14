class Solution {
public:
    string predictPartyVictory(string senate) {
        vector<char> s(senate.begin(), senate.end());

        while (true) {
            int i = 0;
            while (i < s.size()) {
                if (find(s.begin(), s.end(), 'R') == s.end()) {
                    return "Dire";
                }
                if (find(s.begin(), s.end(), 'D') == s.end()) {
                    return "Radiant";
                }
                if (s[i] == 'R') {
                    int j = (i + 1) % s.size();
                    while (s[j] == 'R') {
                        j = (j + 1) % s.size();
                    }
                    s.erase(s.begin() + j);
                    if (j < i) {
                        i--;
                    }
                } else {
                    int j = (i + 1) % s.size();
                    while (s[j] == 'D') {
                        j = (j + 1) % s.size();
                    }
                    s.erase(s.begin() + j);
                    if (j < i) {
                        i--;
                    }
                }
                i++;
            }
        }
    }
};