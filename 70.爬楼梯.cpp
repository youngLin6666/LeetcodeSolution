/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        /* 动态规划 滚筒数组 f(x) = f(x - 2) + f(x - 1)
                            r  =  p       + q
         */
        int p = 0, q = 0, r = 1;
        for(int i = 1; i <= n; i++)
        {
            p = q;
            q = r;
            r = p + q;
        }

        return r;
    }
};
// @lc code=end

