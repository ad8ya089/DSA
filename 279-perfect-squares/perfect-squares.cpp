class Solution {
public:
    //1D DP (Tabulation) --> Method 2
    vector<int>dp;
    int numSquares(int n) {
        dp=vector<int>(n+1,1e9); //take all max values to be 1e9
        dp[0]=0; //n==0 pe return 0 --> base case
        for(int i=1;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                int sq=j*j;
                dp[i]=min(dp[i],1+dp[i-sq]); 
            }
        }
        return dp[n];
    }
};