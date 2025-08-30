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
    int solve(TreeNode* node,int curr){
        if(!node){
            return 0;
        }
        curr=(curr*10)+node->val;
        if(node->left==NULL and node->right==NULL){
            return curr;
        }
        int l=solve(node->left,curr);
        int r=solve(node->right,curr);
        return l+r;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};