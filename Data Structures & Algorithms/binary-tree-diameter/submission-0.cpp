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

        return 1+ max(getHeight(root->left), getHeight(root->right));
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL) return 0;

        // max diameter in left subtree
        int option1 = diameterOfBinaryTree(root->left);
        // max diameter in right subtree
        int option2 = diameterOfBinaryTree(root->right);
        // max diameter spans across left + right
        int option3 = getHeight(root->left) + getHeight(root->right);

        return max(option1, max(option2, option3));
    }
};