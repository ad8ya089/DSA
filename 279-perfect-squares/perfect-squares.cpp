class Solution {
public:
    //2D DP
    int f(int num,int target,vector<vector<int>>&dp){
        if(num==0) return 1e9;
        if(target==0) return 0;
        if(dp[num][target]!=-1) return dp[num][target];
        //take
        int take=1e9;
        if(target>=num*num) take=1+f(num,target-num*num,dp);
        //notTake
        int notTake=f(num-1,target,dp);
        return dp[num][target]=min(take,notTake);
    }
    int numSquares(int n) {
        vector<vector<int>>dp(sqrt(n)+2,vector<int>(n+1,-1)); //num can be 0 as well so..
        return f(sqrt(n),n,dp);
    }
};