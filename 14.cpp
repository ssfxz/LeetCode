class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        
        string prefix = "";
        int p = 0;
        int size = strs.size();
        bool loop = true;
        
        while (loop) {
            char c = '\0';
            for (int i = 0; i < size; ++i) {
                if (p >= strs[i].size()) {
                    loop = false;
                    break;
                }
                
                if (c == '\0') {
                    c = strs[i][p];
                }
                else if (c == strs[i][p]) {
                    continue;
                }
                else {
                    loop = false;
                    break;
                }
            }
            if (loop) {
                prefix.push_back(c);
                ++p;
            }
        }
        return prefix;
    }
};
