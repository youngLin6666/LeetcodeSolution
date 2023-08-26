/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
/* STL方法
        list<int> lst(nums.begin(), nums.end());
        lst.remove(val);
        nums.clear();
        nums.assign(lst.begin(), lst.end());

        return nums.size();
*/

        /* 双指针法 */
        int left = 0, right = nums.size();

        while(left < right)
        {
            if(nums[left] == val)
            {
                nums[left] = nums[right - 1];
                right--;
            }
            else
            {
                left++;
            }
        }

        return left;
    }
};
// @lc code=end

