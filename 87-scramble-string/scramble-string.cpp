class Solution {
public:
    string s1,s2;
    bool f(int len,int i,int j,vector<vector<vector<int>>>&dp){
        string str1=s1.substr(i,len);
        string str2=s2.substr(j,len);
        if(str1==str2) return true;
        if(dp[len][i][j]!=-1) return dp[len][i][j];
        for(int k=1;k<len;k++){
            bool noswap=f(k,i,j,dp) and f(len-k,i+k,j+k,dp);
            bool swap=f(k,i,j+len-k,dp) and f(len-k,i+k,j,dp);
            if(swap or noswap) return dp[len][i][j]=true;
        }
        return dp[len][i][j]=false;
    }
    bool isScramble(string S1, string S2) {
        s1=S1,s2=S2;
        int n=S1.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return f(n,0,0,dp);
    }
};