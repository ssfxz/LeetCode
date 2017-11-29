// Time: O(log(m + n)): http://blog.csdn.net/yutianzuijin/article/details/11499917

// Time: O(m + n)
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();

        int C[m+n];
        int i = 0;
        int j = 0;
        int k = 0;
        
        while(i < m && j < n)
        {
            if(nums1[i] <= nums2[j])
            {
                C[k++] = nums1[i++];
            }
            else
            {
                C[k++] = nums2[j++];
            }
        }
        
        if(i == m)
        {
            while( j < n )
            {
                C[k++] = nums2[j++];
            }
        }
        else
        {
            while( i < m )
            {
                C[k++] = nums1[i++];
            }
        }
        
        k = n + m;
        if( k % 2 == 0)
        {
            return (C[k/2] + C[k/2 - 1])/2.0;
        }
        else
        {
            return C[k/2];
        }
    }
};