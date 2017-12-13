class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        int curr = 0;

        while (curr < s.size()) {
            char c = s[curr++];
            if (c == '(' || c == '{' || c == '[') {
                stack.push_back(c);
            }
            else if (c == ')' || c == '}' || c == ']') {
                if (stack.size() > 0 && isMatch(stack.back(), c)) {
                    stack.pop_back();
                    continue;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return stack.size() == 0;
    }
    
    bool isMatch(char s, char t) {
        unordered_map <char, char> map = {
            {'(', ')'},
            {'{', '}'},
            {'[', ']'}
        };
        
        return map[s] == t;
    }
};