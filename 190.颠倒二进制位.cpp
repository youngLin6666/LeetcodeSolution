/*
 * @lc app=leetcode.cn id=190 lang=cpp
 *
 * [190] 颠倒二进制位
 */

// @lc code=start
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        /* 循环遍历 */
        uint32_t ans = 0;

        for(int i = 0; i < 32 && n > 0; i++)
        {
            ans |= (n & 1) << (31 - i);
            n = (n >> 1);
        }

        return ans;
    }
};
// @lc code=end

