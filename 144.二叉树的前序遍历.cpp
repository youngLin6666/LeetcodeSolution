/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode* root) {
        /* 前序遍历非递归法 */
        vector<int> ans;
        if(root == nullptr)
        {
            return ans;
        }
        stack<TreeNode*> st;

        TreeNode* p = root;

        while(p != nullptr || !st.empty())
        {
            if(p != nullptr)
            {
                st.push(p);
                ans.push_back(p->val);
                p = p->left;
            }
            else
            {
                p = st.top();
                st.pop();
                p = p->right;
            }
        }

        return ans;
    }
};
// @lc code=end

