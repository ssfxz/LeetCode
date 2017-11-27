class Solution {
public:
    int myAtoi(string str) {
        
        long ret = 0;
        bool minus = false;
        int i = 0;
        
        while(isspace(str[i]))
        {
            ++i;
        }
        
        if(str[i] == '+' || str[i] == '-')
        {
            if(str[i] == '-')
            {
                minus = true;
            }
            ++i;
        }
        
        
        while(isdigit(str[i]) && str[i] != '\0')
        {
            ret = ret * 10 + str[i] - '0';
            ++i;
            
            if(ret > INT_MAX)
            {
                return minus ? INT_MIN : INT_MAX;
            }
        }
        
        if(minus)
        {
            ret *= -1;
        }
        
        return (int)ret;
    }
};
