/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        path.push_back(root->val);
        preOrder(root);
        return check_sum(output, targetSum);
    }

private:
    vector<vector<int>> output;
    vector<int> path;
    void preOrder(TreeNode* root) {
        if (!root) {
            return;
        }

        // 一条路径结束的条件，即到达叶子结点时结束
        // 结束时将路径保存到全局数组中
        if (root->left == nullptr && root->right == nullptr) {
            output.push_back(path);
        }

        if (root->left) {
            // 访问该节点时，将该节点记录到路径数组中。
            path.push_back(root->left->val);
            preOrder(root->left);
            // 访问完成后，删除该节点的访问记录
            // 为记录下一条路径做准备
            path.pop_back();
        }

        if (root->right) {
            path.push_back(root->right->val);
            preOrder(root->right);
            path.pop_back();
        }
    }

    // 通过遍历各条路径，确认是否存在满足要求的路径
    bool check_sum(vector<vector<int>>& res, int targetSum) {
        for (int i = 0; i < res.size(); ++i) {
            int sum = 0;
            for (int j = 0; j < res[i].size(); ++j) {
                sum += res[i][j];
            }

            if (sum == targetSum) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

