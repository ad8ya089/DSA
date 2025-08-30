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
    //Brute force --> O(N^2)
    int target;
    int solve(TreeNode* root,long long curr){
        if(!root) return 0;
        curr+=root->val;
        int cnt=0;
        if(curr==target) cnt++;
        int l=solve(root->left,curr);
        int r=solve(root->right,curr);
        return l+r+cnt;
    }
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        target=targetSum;
        return pathSum(root->left,targetSum)+pathSum(root->right,targetSum)+solve(root,0);
    }
};