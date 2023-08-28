/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

// @lc code=start
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
/* 基本方法
        vector<int> ans;

        int iter1 = 0, iter2 = 0;

        while(iter1 < m && iter2 < n)
        {
            if(nums1[iter1] <= nums2[iter2])
            {
                ans.push_back(nums1[iter1]);
                iter1++;
            }
            else
            {
                ans.push_back(nums2[iter2]);
                iter2++;
            }
        }
        
        while(iter1 < m)
        {
            ans.push_back(nums1[iter1]);
            iter1++;
        }
        
        while(iter2 < n)
        {
            ans.push_back(nums2[iter2]);
            iter2++;
        }

        nums1.clear();
        nums1.assign(ans.begin(), ans.end());
        return;
 */

        /* 倒序双指针 nums1[1,2,6,*,*,*] nums2[1,2,5]  p指向nums1的末尾， p1指向
           nums1的6有效数字末尾，p2指向nums2的末尾，
        */
       int p1 = m - 1, p2 = n - 1, p = m + n - 1;

        while(p2 >= 0)
        {
            if(p1 >= 0 && nums1[p1] > nums2[p2])
            {
                nums1[p--] = nums1[p1--];
            }
            else
            {
                nums1[p--] = nums2[p2--];
            }
        }

    }
};
// @lc code=end

