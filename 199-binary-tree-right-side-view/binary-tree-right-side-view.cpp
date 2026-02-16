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
   void  bfs(TreeNode* root, vector<int>& res){
        if(root==NULL)return;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                TreeNode* node = q.front();
                if(i == n-1){
                    res.push_back(node->val);
                }
                q.pop();
                if(node->left !=NULL) q.push(node->left);
                if(node->right !=NULL) q.push(node->right);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        bfs(root,res);
        return res;
    }
};