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
    int target;
    bool solve(TreeNode*root,int curr){
        if(!root) return false;
        curr+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(curr==target) return true;
            return false;
        }
        if(solve(root->left,curr)) return true;
        if(solve(root->right,curr)) return true;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        return solve(root,0);
    }
};