class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        
        
        if(n < 1)
        {
            return n;
        }
        
        for( ; j < n; j++)
        {
            if (nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
    
        return i+1;
    }
};