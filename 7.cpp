class Solution {
public:
    int reverse(int x) {
        long result = 0;
       
        while(x != 0)
        {
            result *= 10;
            result += x % 10;
            x /= 10;
        }
       
        if(x < 0)
        {
           result *= -1;
        }
       
        if(result > 2147483647 || result < -2147483648)
        {
            return 0;
        }
       
        return (int)result;
    }
};
