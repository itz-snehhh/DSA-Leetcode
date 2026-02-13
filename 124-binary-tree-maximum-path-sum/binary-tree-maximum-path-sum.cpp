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
    int Sum(TreeNode*root, int& sum){
        if(!root) return 0;

        int leftSum = Sum(root->left,sum);
        int rightSum = Sum(root->right,sum);
        if(leftSum <0) leftSum = 0;
        if(rightSum<0) rightSum =0;
        sum = max(sum, leftSum+ rightSum + root->val);

        return max(leftSum + root->val, rightSum + root->val);
    }
    int maxPathSum(TreeNode* root) {
        int sum =INT_MIN;
        Sum(root, sum);

        return sum;
       
    }
};