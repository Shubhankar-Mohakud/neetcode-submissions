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
    TreeNode* prev = NULL;
    bool isValid = true;
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;

        if(root->left) isValidBST(root->left);

        if(prev)
            isValid = isValid && (prev->val < root->val);
        
        prev = root;

        if(root->right) isValidBST(root->right);

        return isValid;

    }
};
