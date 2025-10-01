class Solution {
public:
    int solve(int i,vector<int>&dp,vector<int>& costs,int n){
        if(i<0){
            return 1e9;
        }
        if(i==0) return 0;
        if(dp[i]!=-1) return dp[i];
        int one=costs[i-1]+1+solve(i-1,dp,costs,n);
        int two=costs[i-1]+4+solve(i-2,dp,costs,n);
        int three=costs[i-1]+9+solve(i-3,dp,costs,n);
        return dp[i]=min(one,min(two,three));
    }
    int climbStairs(int n, vector<int>& costs) {
        vector<int>dp(n+1,-1);
        return solve(n,dp,costs,n);
    }
};