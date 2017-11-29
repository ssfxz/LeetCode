class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int reach = 0;
        for(int i = 0; i <= reach && i < len; ++i) {
            reach = max(reach, i + nums[i]);
        }
        return reach >= len - 1;
    }
};