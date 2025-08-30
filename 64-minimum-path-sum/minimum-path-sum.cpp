class Solution {
public:
    //Memoization
    int m,n;
    int f(int r,int c,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(r<0 or c<0) return 1e9;
        if(r==0 and c==0) return grid[0][0];
        if(dp[r][c]!=-1) return dp[r][c];
        int up=grid[r][c]+f(r-1,c,grid,dp);
        int left=grid[r][c]+f(r,c-1,grid,dp);
        return dp[r][c]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(m-1,n-1,grid,dp);
    }
};