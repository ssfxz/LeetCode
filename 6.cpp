// https://www.2cto.com/kf/201311/259392.html

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        const int step = (numRows - 1) * 2;
        const int len = s.size();
        string result;
        
        for (int row = 0; row < numRows; ++row) {
            for (int i = row; i < len; i += step) {
                result.push_back(s[i]);
                // not frist row or last row
                if (row != 0 && row != numRows - 1 && i + step - row * 2 < len) {
                    result.push_back(s[i + step - row * 2]);
                }
            }
        }
        return result;
    }
};
