/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

// @lc code=start
class Solution {
public:

    string longestCommonPrefix(const string &strs1, const string &strs2)
    {
        int len = min(strs1.size(), strs2.size()), i = 0;

        for(i = 0; i < len; i++)
        {
            if(strs1[i] != strs2[i])
            {
                break;
            }
        }

        return strs1.substr(0, i);
    }

    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
        {
            return "";
        }

        string prefix = strs[0];
        int count = strs.size(), i = 1;
        for(i = 1; i < count; i++)
        {
            prefix = longestCommonPrefix(prefix, strs[i]);
            if(!prefix.size())
            {
                break;
            }
        }

        return prefix;
    }
};
// @lc code=end

