/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        /* KMP算法 https://www.zhihu.com/question/21923021/answer/281346746 */
        int sizeHays = haystack.size(), sizeNeedle = needle.size();
        vector<int> next(sizeNeedle + 1);
        int i = 0, j = -1;
        next[0] = -1;

        /* 计算next */
        while(i < sizeNeedle)
        {
            if(j == -1 || needle[i] == needle[j])
            {
                i++;j++;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }

        i = 0, j = 0;
        while(i < sizeHays && j < sizeNeedle)
        {
            if(j == -1 || haystack[i] == needle[j])
            {
                i++;j++;
            }
            else
            {
                j = next[j];
            }
        }

        return (j == sizeNeedle ? (i - j) : -1);
    }
};
// @lc code=end

