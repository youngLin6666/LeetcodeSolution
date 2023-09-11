/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(string s) {
        string lower = s;
        transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
        int pleft = 0, pright = lower.length();

        while(pleft < pright)
        {
            while(!isalnum(lower[pleft]) && pleft < lower.length())
            {
                pleft++;
            }

            while(!isalnum(lower[pright]) && pright > 0)
            {
                pright--;
            }

            if(lower[pleft] != lower[pright])
            {
                break;
            }

            pleft++;
            pright--;
        }

        return (pleft < pright ? false : true);
    }
};
// @lc code=end

