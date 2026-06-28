/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root) return{};
        unordered_map<TreeNode*, TreeNode*>parentMap;
        mapParentNodes(root,parentMap);
        return bfsFromTarget(target,parentMap,k);
    }
private:
void mapParentNodes(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&parentMap){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left){
            parentMap[node->left]=node;
            q.push(node->left);
        }
        if(node->right){
            parentMap[node->right]=node;
            q.push(node->right);
        }
    }
}
vector<int>bfsFromTarget(TreeNode*target,unordered_map<TreeNode*,TreeNode*>&parentMap,int k){
    queue<TreeNode*>q;
    unordered_set<TreeNode*>visit;
    q.push(target);
    visit.insert(target);
    int curr=0;
    while(!q.empty()){
        int n=q.size();
        if(curr++==k) break;
        for(int i=0;i<n;++i){
            TreeNode* node=q.front();
            q.pop();
            if(node->left && visit.find(node->left)==visit.end()){
                visit.insert(node->left);
                q.push(node->left);
            }
            if(node->right && visit.find(node->right)==visit.end()){
                visit.insert(node->right);
                q.push(node->right);
            }
            if(parentMap.count(node) && visit.find(parentMap[node])==visit.end()){
                visit.insert(parentMap[node]);
                q.push(parentMap[node]);
            }
        }
    }
            vector<int>res;
            while(!q.empty()){
                res.push_back(q.front()->val);
                q.pop();
            }
            return res;

}
};