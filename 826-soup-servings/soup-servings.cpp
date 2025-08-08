class Solution {
public:
    double f(int a,int b,vector<vector<double>>&dp){
        if(a<=0 and b>0) return 1;
        if(a<=0 and b<=0) return 0.5;
        if(a>0 and b<=0) return 0;
        if(dp[a][b]!=-1) return dp[a][b];
        double ans=0.25*(f(a-4,b,dp)+f(a-3,b-1,dp)+f(a-2,b-2,dp)+f(a-1,b-3,dp));
        return dp[a][b]=ans;
    }
    double soupServings(int n) {
        if(n>5000) return 1;
        vector<vector<double>>dp(201,vector<double>(201,-1));
        int N=ceil(n/25.0);
        return f(N,N,dp);
    }
};