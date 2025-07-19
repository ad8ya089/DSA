class Solution {
public:
    //Tabulation
    int minimumTotal(vector<vector<int>>& triangle) {
    //yaha fixed ending point nahi hai but fix starting point hai isliye start iss baar 0,0 se krenge and will go till (m-1)th row FOR MEMOIZATION
        //Memoization --> 0 to m-1
        //Tabulation --> m-1 to 0 hoga
        int m=triangle.size();
        vector<vector<int>>dp(m,vector<int>(m,0));
        for(int c=0;c<m;c++){ //last row ka length bhi m hoga 
            dp[m-1][c]=triangle[m-1][c];
        }
        for(int r=m-2;r>=0;r--){
            for(int c=r;c>=0;c--){
                int down=triangle[r][c]+dp[r+1][c];
                int diag=triangle[r][c]+dp[r+1][c+1];
                dp[r][c]=min(down,diag);
            }
        }
        return dp[0][0];
    }
};