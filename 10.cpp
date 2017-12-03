// Solution1
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();

        if (lenS == 0) {
            if (lenP == 0) {
                return true;
            }
            else if (lenP >= 2 && p[1] == '*') {
                string newP = p.substr(2, lenP - 2);
                return isMatch(s, newP);
            }
            else {
                return false;
            }
        }
        else if (lenP == 0) {
            return false;
        }
        else {
            if (s[0] == p[0] || p[0] == '.') {
                string newS = s.substr(1, lenS - 1);
                if (lenP >= 2 && p[1] == '*') {
                    string newP = p.substr(2, lenP - 2);
                    return isMatch(newS, p) || isMatch(s, newP);
                }
                else {
                    string newP = p.substr(1, lenP - 1);
                    return isMatch(newS, newP);
                }
            }
            else if (lenP >= 2 && p[1] == '*') {
                string newP = p.substr(2, lenP - 2);
                return isMatch(s, newP);
            }
            else {
                return false;
            }
        }
    }
};

// Solution2
class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.size(), lenP = p.size();
    
        if (lenP == 0) {
            return lenS == 0;
        }
        else if (lenP >= 2 && p[1] == '*') {
            if (lenS == 0) {
                string newP = p.substr(2, lenP - 2);
                return isMatch(s, newP);
            }
            else {
                if (s[0] == p[0] || p[0] == '.') {
                    string newS = s.substr(1, lenS - 1);
                    string newP = p.substr(2, lenP - 2);
                    return isMatch(newS, p) || isMatch(s, newP);
                }
                else {
                    string newP = p.substr(2, lenP - 2);
                    return isMatch(s, newP);
                }
            }
        }
        else {
            if (lenS == 0) {
                return false;
            }
            else {
                if (s[0] == p[0] || p[0] == '.') {
                    string newS = s.substr(1, lenS - 1);
                    string newP = p.substr(1, lenP - 1);
                    return isMatch(newS, newP);
                }
                else {
                    return false;
                }
            }
        }
    }
};
