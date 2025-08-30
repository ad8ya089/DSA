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
    string mn="~";
    void solve(TreeNode* root,string curr){
        if(!root){
            return;
        }
        char c=(char)(root->val+'a');
        curr=curr+c;
        if(root->left==NULL and root->right==NULL){
            reverse(curr.begin(),curr.end());
            mn=min(mn,curr);
            return;
        }
        solve(root->left,curr);
        solve(root->right,curr);
    }
    string smallestFromLeaf(TreeNode* root) {
        for(int i=1;i<=8500;i++){
            mn+='z';
        }
        solve(root,"");
        return mn;
    }
};