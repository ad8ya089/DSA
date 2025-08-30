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
    void solve(TreeNode* root,string curr,vector<string>&ans){
        if(!root){
            return;
        }
        if(root->val<0) curr+="-";
        string s=to_string(abs(root->val));
        curr+=s;
        if(root->left==NULL and root->right==NULL){
            ans.push_back(curr);
            return;
        }
        curr+="->";
        solve(root->left,curr,ans);
        solve(root->right,curr,ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        solve(root,"",ans);
        return ans;
    }
};