class Solution {
public:
    //1D DP (Memo)
    vector<int>dp;
    int solve(int n){
        if(n<=0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=1e9;
        for(int i=1;i*i<=n;i++){
            int sq=i*i;
            ans=min(ans,1+solve(n-sq)); //take (sab case hi dekh rha na toh notTake auto hai)
        }
        return dp[n]=ans;
    }
    int numSquares(int n) {
        dp=vector<int>(n+1,-1);
        return solve(n);
    }
};