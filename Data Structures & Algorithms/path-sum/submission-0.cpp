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
    bool solve(TreeNode* root, int targetSum){
        // base case 1
        if(root==NULL) return false;
        // base case 2
        if(root->left==NULL && root->right==NULL) return root->val == targetSum;
        
        return solve(root->left, targetSum-root->val) || solve(root->right, targetSum-root->val);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root, targetSum);
    }
};