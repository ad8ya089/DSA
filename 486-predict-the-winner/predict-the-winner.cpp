class Solution {
public:
    //Memoization (Top-Down) --> O(n^2)
    int n;
    int maxDiff(vector<int>&nums,int left,int right,vector<vector<int>>&dp){
        if(left==right){
            return nums[left];
        }
        if(dp[left][right]!=-1) return dp[left][right];
        int scoreL=nums[left]-maxDiff(nums,left+1,right,dp);
        int scoreR=nums[right]-maxDiff(nums,left,right-1,dp);
        return dp[left][right]=max(scoreL,scoreR);
    }
    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int mxD=maxDiff(nums,0,n-1,dp);
        return mxD>=0;
    }
};