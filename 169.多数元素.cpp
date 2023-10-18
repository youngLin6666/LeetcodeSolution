/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
/* 常规方法
        int len = nums.size();
        int midLen = len / 2;
        int count = 1;

        sort(nums.begin(), nums.end());

        int tmp = nums[0];

        for(int i = 1; i < len; i++)
        {
            if(tmp == nums[i])
            {
                count++;
                if(count > midLen)
                {
                    break;
                }
            }
            else
            {
                tmp = nums[i];
                count = 1;
            }
        }

        return tmp;
*/

    /* 哈希表
        int len = nums.size();
        int midLen = len / 2;
        int majority = 0;
        unordered_map<int, int> umap;

        for(auto num : nums)
        {
            umap[num]++;
            if(umap[num] > midLen)
            {
                majority = num;
                break;
            }
        }

        return majority;
    */

    /* Boyer-Moore 投票算法 */
        int count = 0;
        int candidate = 0;

        for(auto num : nums)
        {
            if(count <= 0)
            {
                candidate = num;
            }

            count += ( (candidate == num) ? 1 : -1);
        }
        return candidate;
    }
};
// @lc code=end

