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
    int mx=INT_MIN;
    int dfs(TreeNode* root){
        if(!root) return 0;
        int mxLeft=max(0,dfs(root->left)); //negative value ko intake hi mat kar
        int mxRight=max(0,dfs(root->right)); //negative value ko intake hi mat kar
        mx=max(mx,root->val+mxLeft+mxRight);
        return root->val+max(mxLeft,mxRight);
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return mx;
    }
};