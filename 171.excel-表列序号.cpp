/*
 * @lc app=leetcode.cn id=171 lang=cpp
 *
 * [171] Excel 表列序号
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string columnTitle) {
        reverse(columnTitle.begin(), columnTitle.end());

        long j = 1;
        int i = 0, ans = 0;
        for(auto ch : columnTitle)
        {
            i = ch - 'A' + 1;
            ans += (i * j);

            j *= 26;
        }

        return ans;
    }
};
// @lc code=end

