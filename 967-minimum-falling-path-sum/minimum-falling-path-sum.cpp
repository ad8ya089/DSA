class Solution {
public:
    //Tabulation         
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int c=0;c<n;c++){
            dp[0][c]=mat[0][c];
        }
        for(int r=1;r<n;r++){
            for(int c=0;c<n;c++){
                int below=mat[r][c]+dp[r-1][c];
                int leftD=mat[r][c],rightD=mat[r][c];
                if(c-1>=0) leftD+=dp[r-1][c-1];
                else leftD=1e9;
                if(c+1<n) rightD+=dp[r-1][c+1];
                else rightD=1e9;
                dp[r][c]=min(below,min(leftD,rightD));
            }
        }
        int mn=INT_MAX;
        for(int c=0;c<n;c++){
            mn=min(mn,dp[n-1][c]);
        }
        return mn;
    }
};