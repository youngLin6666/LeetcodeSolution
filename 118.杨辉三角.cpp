/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int> preRow;//上一行
        for(int i = 0; i < numRows; i++)
        {
            vector<int> currentRow(i+1,1); //当前行
            for(int j = 1; j < i; j++)
            {
                currentRow[j] = preRow[j-1] + preRow[j];
            }
            preRow = currentRow;
            res.push_back(currentRow);
        }

        return res;
    }
};
// @lc code=end

