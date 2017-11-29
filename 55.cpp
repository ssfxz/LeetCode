class Solution {
public:
    bool canJump(vector<int>& nums) {
        int step = nums[0];
        int len = nums.size();
        
        for(int i = 0; i < len; i++)
        {
            if(step-- <= 0)
                return false;
            
            if(step < nums[i])
            {  
                step = nums[i];  
            }
            
            if(i + 1  + step >= len)
            {
                return true;
            }
        }
        return false;
    }
};