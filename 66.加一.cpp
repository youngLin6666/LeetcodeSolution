/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int r = digits.size() - 1;
        bool carry = false;
        vector<int> v(digits.begin(), digits.end());

        reverse(v.begin(), v.end());
        auto iter = v.begin();

        while(iter != v.end())
        {
            if(*iter < 9)
            {
                *iter = *iter + 1;
                carry = false;
                break;
            }
            else
            {
                *iter = 0;
                carry = true;
            }

            iter++;
        }

        if(carry)
        {
            v.push_back(1);
        }
        reverse(v.begin(), v.end());

        return v;
    }
};
// @lc code=end

