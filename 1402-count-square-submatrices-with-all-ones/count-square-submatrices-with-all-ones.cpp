class Solution {
public:
    int countSquares(vector<vector<int>>& mat) {
        //Tabulation
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        for(int j=0;j<n;j++) dp[0][j]=mat[0][j]; //1st row replicate krdo
        for(int i=0;i<m;i++) dp[i][0]=mat[i][0]; //1st column replicate krdo
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                if(mat[i][j]==0) dp[i][j]=0;
                else dp[i][j]=1+min(dp[i-1][j-1],min(dp[i][j-1],dp[i-1][j]));
            }
        }
        int sum=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                sum+=dp[i][j];
            }
        }
        return sum;
    }
};