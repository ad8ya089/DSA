class Solution {
public:
    //Tabulation
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int r=0;r<m;r++){
            for(int c=0;c<n;c++){
                if(r==0 and c==0) dp[r][c]=1;
                else{
                    int left=0,up=0;
                    if(c-1>=0) left=dp[r][c-1];
                    if(r-1>=0) up=dp[r-1][c];
                    dp[r][c]=left+up;
                }
            }
        }
        return dp[m-1][n-1];
    }
};