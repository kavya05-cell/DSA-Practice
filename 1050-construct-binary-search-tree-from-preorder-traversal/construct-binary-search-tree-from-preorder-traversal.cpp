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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       int idx=0;
       return buildTree(preorder,idx,INT_MAX);
    }
    private:
    TreeNode* buildTree(vector<int>&preorder,int& idx, int maxx){
        if(idx>=preorder.size() || preorder[idx]>maxx) return nullptr;
        TreeNode* root= new TreeNode(preorder[idx++]);
        root->left=buildTree(preorder,idx,root->val);
        root->right=buildTree(preorder,idx,maxx);
        return root;
    }
};