/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> preRow;
        for(int i = 0; i < rowIndex + 1; i++)
        {
            vector<int> curRow(i + 1, 1);
            for(int j = 1; j < i; j++)
            {
                curRow[j] = preRow[j - 1] + preRow[j];
            }
            preRow = curRow;
        }

        return preRow;
    }
};
// @lc code=end

