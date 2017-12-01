class Solution {
public:
    int romanToInt(string s) {
        const int len = s.size();
        int result = 0;
        int curr = 0;
        
        unordered_map<char, int> map = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                                        {'C', 100}, {'D', 500}, {'M', 1000}};
        
        for(int i = len; i >= 0; --i) {
            calc(map[s[i]], &curr, &result);
        }
        return result;
    }
    
    void calc(int value, int * curr, int * result) {
        if (*curr <= value) {
            *result += value;
            *curr = value;
        }
        else {
            *result -= value;
        }
    }
};
