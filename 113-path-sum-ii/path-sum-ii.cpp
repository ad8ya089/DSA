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
    void solve(TreeNode* root,int curr,vector<int>&v,vector<vector<int>>&ans){
        if(!root){
            return;
        }
        v.push_back(root->val);
        curr+=root->val;
        if(root->left==NULL and root->right==NULL){
            if(curr==target){
                ans.push_back(v);
            }
            v.pop_back();
            return;
        }
        solve(root->left,curr,v,ans);
        solve(root->right,curr,v,ans);
        v.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        target=targetSum;
        vector<vector<int>>ans;
        vector<int>v;
        solve(root,0,v,ans);
        return ans;
    }
};