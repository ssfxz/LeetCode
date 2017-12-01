class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        
        // x的数量级
        int magnitude = pow(10, floor(log10(x)));
        
        while (x > 0) {
            int left = x / magnitude;
            int right = x % 10;
            
            if (left != right) {
                return false;
            }
            
            x = x % magnitude / 10;
            magnitude /= 100;
        }
        
        return true;
    }
};
