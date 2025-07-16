class Solution {
public:
    //Memoization
    int f(int n,vector<int>&dp){
        if(n<0) return 0;
        if(n==0 or n==1) return 1;
        if(dp[n]!=-1) return dp[n]; //overlapping subsequences
        int one=f(n-1,dp);
        int two=f(n-2,dp);
        return dp[n]=one+two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        int ans=f(n,dp);
        return ans;
    }
};