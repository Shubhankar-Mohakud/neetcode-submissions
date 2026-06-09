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
    int getHeight(TreeNode* root){
        if(root==NULL) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(root==NULL) return true;

        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        bool status = abs(leftHeight - rightHeight) <= 1 ? true : false;

        bool leftSubtree = isBalanced(root->left);
        bool rightSubtree = isBalanced(root->right);

        return status && leftSubtree && rightSubtree;
    }
};
