class Solution {
public:
        
    unordered_map <int, string> map = {
        {0, " "},
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"}
    };
    
    vector <string> letterCombinations(string digits) {
        vector <string> result;
        string buffer;
        convert(result, digits, 0, buffer);
        return result;
    }
    
    void convert(vector <string> &result, string digits, int curr, string buffer) {
        if (curr == digits.size() && buffer != "") {
            result.push_back(buffer);
            return;
        }
        else {
            string dict = map[digits[curr] - '0'];
            for (int i = 0; i < dict.size(); ++i) {
                buffer.push_back(dict[i]);
                convert(result, digits, curr + 1, buffer);
                buffer.pop_back();
            }
        }
    }
};
