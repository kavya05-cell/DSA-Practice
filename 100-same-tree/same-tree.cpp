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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*>q1;
        queue<TreeNode*>q2;
        q1.push(p);
        q2.push(q);
        while(!q1.empty() && !q2.empty()){
            for(int i=q1.size();i>0;i--){
                TreeNode*nodep=q1.front();
                q1.pop();
                TreeNode*nodeq=q2.front();
                q2.pop();
                if(!nodep && !nodeq) continue;
                if(!nodep || !nodeq || nodep->val !=nodeq->val) return false;
                q1.push(nodep->left);
                q1.push(nodep->right);
                q2.push(nodeq->left);
                q2.push(nodeq->right);
            }
        }
        return true;
    }
};