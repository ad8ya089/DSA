class Solution {
public:
    //1D DP (Tabulation) --> Method 1
    vector<int>dp;
    int numSquares(int n) {
        dp=vector<int>(n+1,0);
        for(int i=1;i<=n;i++){
            dp[i]=i; //max ans for any ith value is i itself
            for(int j=1;j*j<=i;j++){
                int sq=j*j;
                dp[i]=min(dp[i],1+dp[i-sq]); 
            }
        }
        return dp[n];
    }
};