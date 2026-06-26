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
    int res=INT_MIN;
    int getmax(TreeNode*root){
        if(!root) return 0;
        int left=getmax(root->left);
        int right=getmax(root->right);
        int path=root->val+std::max(left,right);
        return std::max(0,path);
    }
    void dfs(TreeNode*root){
        if(!root) return;
        int left=getmax(root->left);
        int right=getmax(root->right);
        res=max(res,root->val+left+right);
        dfs(root->left);
        dfs(root->right);
    }
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return res;
    }
};