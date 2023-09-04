/*
 * @lc app=leetcode.cn id=110 lang=cpp
 *
 * [110] 平衡二叉树
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
/* 自顶向下递归 o(n^2) */
/*
    int depth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }
        else
        {
            return (max(depth(root->left), depth(root->right)) + 1);
        }
    }

    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
        {
            return true;
        }
        else
        {
            return abs(depth(root->left) - depth(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
        }
    }
*/

/* 自底向下 */
    int depth(TreeNode* root)
    {
        if(root == NULL)
        {
            return 0;
        }

        int lefthight = depth(root->left);
        int righthight = depth(root->right);

        if(lefthight == -1 || righthight == -1 || abs(lefthight - righthight) > 1)
        {
            return -1;
        }
        else
        {
            return max(lefthight, righthight) + 1;
        }
    }

    bool isBalanced(TreeNode* root) {
        return depth(root) >= 0;
    }

};
// @lc code=end

