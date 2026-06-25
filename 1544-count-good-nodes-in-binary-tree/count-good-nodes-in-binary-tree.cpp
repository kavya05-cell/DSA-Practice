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
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
private:
    int dfs(TreeNode* node,int maxx){
        if(!node) return 0;
        int res=(node->val>=maxx) ? 1 : 0;
        maxx=max(maxx,node->val);
        res+=dfs(node->left,maxx);
        res+=dfs(node->right,maxx);
        return res;
    }
};