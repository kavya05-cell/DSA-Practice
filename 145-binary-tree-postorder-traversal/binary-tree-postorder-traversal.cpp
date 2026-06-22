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
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int>res;
       TreeNode* cur=root;
       while(cur){
        if(!cur->right){
            res.push_back(cur->val);
            cur=cur->left;
        }
        else{
            TreeNode*prev=cur->right;
            while(prev->left && prev->left!=cur){
                prev=prev->left;
            }
            if(!prev->left){
                res.push_back(cur->val);
                prev->left=cur;
                cur=cur->right;
            }
            else{
                prev->left=nullptr;
                cur=cur->left;
            }
        }
       }
       reverse(res.begin(),res.end());
       return res;
    }
};