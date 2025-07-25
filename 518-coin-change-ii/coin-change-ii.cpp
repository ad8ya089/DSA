class Solution {
public:
    //Memoization
    int f(int ind,int target,vector<int>&coins,vector<vector<int>>&dp){
        if(target==0) return 1;
        if(ind==0){
            if(target%coins[0]==0) return 1;
            return 0;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notTake=f(ind-1,target,coins,dp);
        int take=0;
        if(target>=coins[ind]) take=f(ind,target-coins[ind],coins,dp); //take krne ke baad bhi same index pe reh laadle
        return dp[ind][target]=take+notTake;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(n-1,amount,coins,dp);
    }
};