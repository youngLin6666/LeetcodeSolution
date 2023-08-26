/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 || (x % 10 == 0 && x != 0))
        {
            return false;
        }

        int halfOfx = 0;
        while(x > halfOfx)
        {
            halfOfx = halfOfx * 10 + x % 10;
            x = x / 10;
        }
        
        return (x == halfOfx || x == halfOfx / 10);
    }
};
// @lc code=end

