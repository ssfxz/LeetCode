class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int ans = numeric_limits<int>::max();
        int min_diff = numeric_limits<int>::max();
        
        if (nums.size() < 3) {
            return ans;
        }

        // Make nums in increasing order. Time: O(nlogn)
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i == 0 || nums[i] != nums[i - 1]) {  // Skip duplicated.
                for (int j = i + 1, k = nums.size() - 1; j < k; ) {  // Time: O(n) for each i.
                    if (j - 1 > i  && nums[j] == nums[j - 1]) {  // Skip duplicated.
                        ++j;
                    } else if (k + 1 < nums.size() && nums[k] == nums[k + 1]) {  // Skip duplicated.
                        --k;
                    } else {
                        const auto sum = nums[i] + nums[j] + nums[k];
                        if (sum > target) {  // Should decrease sum.
                            --k;
                        } else if (sum < target) {  // Should increase sum.
                            ++j;
                        } else {
                            return target;
                        }
    
                        if (abs(sum - target) < min_diff) {
                            min_diff = abs(sum - target);
                            ans = sum;
                        }
                    }
                }
            }
        }

        return ans;
    }
};
