/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hTable;
        int len = nums.size(), i = 0;

        for(i = 0;i < len; i++)
        {
            auto it = hTable.find(target - nums[i]);

            if(it != hTable.end())
            {
                return {it->second, i};
            }
            hTable[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

