/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int len = s.size();

        if(len % 2 != 0)
        {
            return false;
        }

        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        stack<char> st;
        for(auto c : s)
        {
            if(pairs.count(c))
            {
                if(st.empty() || st.top() != pairs[c])
                {
                    return false;
                }

                st.pop();
            }
            else
            {
                st.push(c);
            }
        }

        return st.empty();
    }
};
// @lc code=end

