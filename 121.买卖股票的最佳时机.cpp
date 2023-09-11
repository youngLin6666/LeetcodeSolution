/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {

/* 超时了
        int len = prices.size();
        int maxNum = INT_MIN;
        for(int i = 0; i < len; i++)
        {
            for(int j = i; j < len; j++)
            {
                maxNum = max(prices[j] - prices[i], maxNum);
            }
        }

        return maxNum;
 */

        int minprofit = INT_MAX;
        int maxprofit = 0;

        for(int todayPrice : prices)
        {
            maxprofit = max(maxprofit, todayPrice - minprofit);
            minprofit = min(minprofit, todayPrice);
        }

        return maxprofit;
    }
};
// @lc code=end

