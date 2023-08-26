/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */

// @lc code=start


class Solution {

    unordered_map<char, int> map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };


public:
    int romanToInt(string s) {
        int len = s.size(), res = 0, i = 0;

/* 方法一 case大法
        while(i < len)
        {
            switch (s[i])
            {
            case 'M':
                res += 1000;
                i++;
                break;
            
            case 'C':
                if(s[i+1] == 'M')
                {
                    res += 900;
                    i += 2;
                }
                else if(s[i+1] == 'D')
                {
                    res += 400;
                    i += 2;
                }
                else
                {
                    res += 100;
                    i++;
                }
                break;

            case 'X':
                if(s[i+1] == 'L')
                {
                    res += 40;
                    i += 2;
                }
                else if(s[i+1] == 'C')
                {
                    res += 90;
                    i += 2;
                }
                else
                {
                    res += 10;
                    i++;
                }
                break;

            case 'I':
                if(s[i+1] == 'X')
                {
                    res += 9;
                    i += 2;
                }
                else if(s[i+1] == 'V')
                {
                    res += 4;
                    i += 2;
                }
                else
                {
                    res += 1;
                    i++;
                }
                break;

            case 'V':
                res += 5;
                i++;
                break;

            case 'L':
                res += 50;
                i++;
                break;

            case 'D':
                res += 500;
                i++;
                break;

            default:
                break;
            }
        }

        return res;
*/

/* 方法二 算术规律小的数字在大的数字左边做减法，否则为加法 */
        for(i = 0; i < len; i++)
        {
            int value = map[s[i]];
            if(i < len - 1 && value < map[s[i + 1]])
            {
                res -= value;
            }
            else
            {
                res += value;
            }
        }

        return res;
    }
};
// @lc code=end

