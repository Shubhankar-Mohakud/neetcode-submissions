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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> temp;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            if(q.front()==NULL){
                ans.push_back(temp);
                while(temp.size()!=0) temp.pop_back();
                q.pop();
                if(!q.empty()){
                    q.push(NULL);
                }
            } else {
                TreeNode* node = q.front();
                temp.push_back(node->val);
                q.pop();

                if(node->left) q.push(node->left);

                if(node->right) q.push(node->right);
            }
        }
        return ans;
    }
};
