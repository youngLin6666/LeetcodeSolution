/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        /* a ⊕ b ⊕ a =   b ⊕ a ⊕ a     = b ⊕ ( a ⊕ a )    = b ⊕ 0    = b */
        /* 除了字符串都可以用这个方法 */

        int single = 0;
        for(auto itnum : nums)
        {
            single ^= itnum;
        }

        return single;
    }
};
// @lc code=end

