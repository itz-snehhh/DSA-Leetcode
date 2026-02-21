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
    bool findPath(TreeNode* root, TreeNode* node, vector<TreeNode*>& path) {
        if (root == NULL)
            return false;

        path.push_back(root);
        if (root->val == node->val)
            return true;

        if (findPath(root->left, node, path) ||
            findPath(root->right, node, path)) {
            return true;
        }

        path.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path1;
        vector<TreeNode*> path2;
        findPath(root, p, path1);
        findPath(root, q, path2);

        int n = path1.size() < path2.size() ? path1.size() : path2.size();
        TreeNode* ans;
        for (int i = 0; i < n; i++) {
            if (path1[i] == path2[i]) {
                ans = path1[i];
            } else
                return ans;
        }
        return ans;
    }
};