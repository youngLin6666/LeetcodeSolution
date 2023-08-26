/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int fast = s.size() - 1, count = 0, slow = -1;

        while(fast >= 0)
        {
            if( (s[fast] <= 'z' && s[fast] >= 'a') || (s[fast] <= 'Z' && s[fast] >= 'A') )
            {
                slow = fast;
                break;
            }
            fast--;
        }
        
        while(slow >= 0)
        {
            if(s[slow] == ' ')
            {
                break;
            }

            slow--;
            count++;
        }
        

        return count;
    }
};
// @lc code=end

