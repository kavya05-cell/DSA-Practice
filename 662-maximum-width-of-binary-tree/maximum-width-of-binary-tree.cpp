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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int maxw=0;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            unsigned long long mini=q.front().second;
            int first=0;
            int last=0;
            for(int i=0;i<n;i++){
                unsigned long long curr=q.front().second-mini;
                TreeNode* node=q.front().first;
                q.pop();
                if(i==0) first=curr;
                if(i==n-1) last=curr;
                if(node->left) q.push({node->left,2*curr+1});
                if(node->right) q.push({node->right,2*curr+2});
            }
            maxw=max(maxw,last-first+1);
        }
        return maxw;
    }
};