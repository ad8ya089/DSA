class Solution {
public:
    //Memoization
    int f(int r,int c,vector<vector<int>>&dp,int m,int n){
        if(r<0 or c<0) return 0;
        if(r==0 and c==0) return 1;
        if(dp[r][c]!=-1) return dp[r][c];
        int left=f(r,c-1,dp,m,n);
        int up=f(r-1,c,dp,m,n);
        return dp[r][c]=left+up;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,m,n);
    }
};