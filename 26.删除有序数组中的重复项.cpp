/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size(), i = 1, j = 1;
        if(len == 0)
        {
            return 0;
        }

        while(j < len)
        {
            if(nums[j - 1] != nums[j])
            {
                nums[i] = nums[j];
                i++;
            }
            j++;
        }

        return i;
    }
};
// @lc code=end

