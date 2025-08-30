class Solution {
public:
    //Tabulation
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 and c==0) {dp[r][c]=grid[r][c];continue;}
                int up=INT_MAX,left=INT_MAX;
                if(r-1>=0) up=grid[r][c]+dp[r-1][c];
                if(c-1>=0) left=grid[r][c]+dp[r][c-1];
                dp[r][c]=min(up,left);
            }
        }
        return dp[m-1][n-1];
    }
};