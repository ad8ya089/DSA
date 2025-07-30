class Solution {
public:
    int M=1e9+7;
    int f(int ind,int A,int L,vector<vector<vector<int>>>&dp,int n){
        if(A>1 or L>2) return 0;
        if(ind==n) return 1;
        if(dp[ind][A][L]!=-1) return dp[ind][A][L];
        int ans=0;
        ans=(ans+f(ind+1,A,0,dp,n))%M; //Take P
        ans=(ans+f(ind+1,A,L+1,dp,n))%M; //Take L
        ans=(ans+f(ind+1,A+1,0,dp,n))%M; //Take A
        return dp[ind][A][L]=ans%M;
    }
    int checkRecord(int n) {
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,0,0,dp,n);
    }
};