class Solution {
public:
    int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(ind<0) return 0;
        if(dp[ind][target]!=-1) return dp[ind][target];
        int sum=0;
        int take=0;
        while(sum<=target){
            take+=f(ind-1,target-sum,coins,dp);
            sum+=coins[ind];
        }
        return dp[ind][target]=take;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        sort(coins.begin(),coins.end());
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};