/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == nullptr)
        {
            return ans;
        }

        stack<TreeNode*> st;
        TreeNode* p = root, *pre = nullptr;

        while(p != nullptr || !st.empty())
        {
            while(p != nullptr)
            {
                st.push(p);
                p = p->left;
            }

            p = st.top();
            st.pop();

            if(p->right == NULL || p->right == pre)
            {
                ans.push_back(p->val);
                pre = p;
                p = nullptr;
            }
            else
            {
                st.push(p);
                p = p->right;
            }
        }

        return ans;
    }
};
// @lc code=end

