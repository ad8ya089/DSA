class Solution {
public:
    //Memoization
    int f(int ind,vector<int>nums,vector<int>&dp){
        if(ind<0) return 0;
        if(ind==0) return dp[ind]=nums[0];
        if(dp[ind]!=-1) return dp[ind];
        int take=f(ind-2,nums,dp)+nums[ind];
        int notTake=f(ind-1,nums,dp)+0;
        return dp[ind]=max(take,notTake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n,-1);
        return f(n-1,nums,dp);
    }
};