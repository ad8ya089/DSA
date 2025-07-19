class Solution {
public:
    int m,n;
    int f(int r,int c,vector<vector<int>>&dp,vector<vector<int>>& grid){
        if(r==0 and c==0) return grid[0][0];
        if(dp[r][c]!=-1) return dp[r][c];
        int up=INT_MAX,left=INT_MAX;
        if(r-1>=0) up=grid[r][c]+f(r-1,c,dp,grid);
        if(c-1>=0) left=grid[r][c]+f(r,c-1,dp,grid);
        return dp[r][c]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,dp,grid);
    }
};