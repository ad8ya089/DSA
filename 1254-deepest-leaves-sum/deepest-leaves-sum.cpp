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
    int sum=0,mx;
    int maxDepth(TreeNode* root){
        if(!root) return 0;
        return 1+max(maxDepth(root->left),maxDepth(root->right));
    }
    void dfs(TreeNode* root,int d){
        if(!root) return;
        if(!root->left and !root->right and d==mx-1){
            sum+=root->val;
            return;
        }
        dfs(root->left,d+1);
        dfs(root->right,d+1);
    }
    int deepestLeavesSum(TreeNode* root) {
        int MX=maxDepth(root);
        mx=MX;
        dfs(root,0);
        return sum;
    }
};