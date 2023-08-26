/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        int l = 0, r = x, ans = -1;

        while(l <= r)
        {
            int mid = l + (r - l) / 2;
            /* 注意这里是(long long)mid 强转换成long long类型，所以 long long 类型 * int 类型结果转换为long long类型
               这个时候不会发生溢出

               但是,如果这样子写(long long)(mid * mid)，就是int类型 * int类型,算出是int类型后再强转成long long类型
               然而int类型 * int类型的结果是int类型,当int类型是很大的数字的时候，这个时候发生溢出再进行强转已经没有用了
            */
            if((long long)mid * mid <= x)
            {
                l = mid + 1;
                ans = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        
        return ans;
    }
};
// @lc code=end

