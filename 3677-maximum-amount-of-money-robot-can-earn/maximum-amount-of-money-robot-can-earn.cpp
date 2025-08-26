class Solution {
public:
    int m,n;
    int f(int r,int c,int cap,vector<vector<vector<int>>>&dp,vector<vector<int>>&coins){
        if(r==m-1 and c==n-1){
            if(cap>0 and coins[r][c]<0) return 0;
            return coins[r][c];
        }
        if(dp[r][c][cap]!=INT_MIN) return dp[r][c][cap];
        int rightDo=INT_MIN,rightDont=INT_MIN,downDo=INT_MIN,downDont=INT_MIN;
        if(coins[r][c]<0){
            if(cap>0 and c+1<n) rightDo=f(r,c+1,cap-1,dp,coins);
            if(c+1<n) rightDont=coins[r][c]+f(r,c+1,cap,dp,coins);
            if(cap>0 and r+1<m) downDo=f(r+1,c,cap-1,dp,coins);
            if(r+1<m) downDont=coins[r][c]+f(r+1,c,cap,dp,coins);
        }
        else{
            if(c+1<n) rightDo=coins[r][c]+f(r,c+1,cap,dp,coins);
            if(c+1<n) rightDont=coins[r][c]+f(r,c+1,cap,dp,coins);
            if(r+1<m) downDo=coins[r][c]+f(r+1,c,cap,dp,coins);
            if(r+1<m) downDont=coins[r][c]+f(r+1,c,cap,dp,coins);
        }
        return dp[r][c][cap]=max(max(rightDo,rightDont),max(downDo,downDont));
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        return f(0,0,2,dp,coins);
    }
};