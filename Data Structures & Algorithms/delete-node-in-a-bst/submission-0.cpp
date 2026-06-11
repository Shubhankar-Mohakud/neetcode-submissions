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
    int getJustSmaller(TreeNode* root){
        while(root->right != NULL) root = root->right;

        return root->val;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;

        if(root->val==key){
            // Leaf Node
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            // Only left child
            if(root->left != NULL && root->right==NULL){
                TreeNode* leftChild = root->left;
                root->left=NULL;
                delete root;
                return leftChild;
            }
            // Only right child
            if(root->left == NULL && root->right != NULL){
                TreeNode* rightChild = root->right;
                root->right=NULL;
                delete root;
                return rightChild;
            }
            // Has both child
            if(root->left != NULL && root->right != NULL){
                int justSmall = getJustSmaller(root->left);
                root->val = justSmall;
                root->left = deleteNode(root->left, justSmall);
                return root;
            }
        } else {
            if(key < root->val) 
                root->left = deleteNode(root->left, key);
            else 
                root->right = deleteNode(root->right, key);
        }
        return root;
    }
};