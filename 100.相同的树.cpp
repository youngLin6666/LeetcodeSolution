/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*> stkp;
        stack<TreeNode*> stkq;

        if( (p == nullptr && q != nullptr) || (p != nullptr && q == nullptr) )
        {
            return false;
        }

        while(p != nullptr || q != nullptr || (!stkp.empty() && !stkq.empty()) )
        {
            while(p != nullptr && q != nullptr)
            {
                stkp.push(p);
                stkq.push(q);

                p = p->left;
                q = q->left;
            }

            if(p == nullptr && q == nullptr)
            {
                p = stkp.top();
                q = stkq.top();
                if(p->val == q->val)
                {
                    p = p->right;
                    q = q->right;

                    stkp.pop();
                    stkq.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }

        return stkp.empty() && stkq.empty();
    }
};
// @lc code=end

