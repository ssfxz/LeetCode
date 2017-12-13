class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
        vector<vector<int>> ans;
        
        if (nums.size() < 4) {
            return ans;
        }

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 3; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                for (int j = i + 1; j < nums.size() - 2; ++j) {
                    if (j != i + 1 && nums[j] == nums[j - 1]) {
                        continue;
                    }
                    int sum = target - nums[i] - nums[j];
                    int left = j + 1, right = nums.size() - 1;
                    while (left < right) {
                        if (nums[left] + nums[right] == sum) {
                            ans.push_back({nums[i], nums[j], nums[left], nums[right]});
                            ++left, --right;
                            while (left < right && nums[left] == nums[left - 1]) {
                                ++left;
                            }
                            while (left < right && nums[right] == nums[right + 1]) {
                                --right;
                            }
                        } else {
                            if (nums[left] + nums[right] > sum) {
                                --right;
                            } else {
                                ++left;
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};