class Solution {
public:
    //Memoization
    int n1,n2;
    int f(int ind1,int ind2,string &s1, string &s2,vector<vector<int>>&dp){
        if(ind1==0 and ind2==0){
            return s1[ind1]==s2[ind2];
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(ind1==0){
            if(s1[ind1]==s2[ind2]) return 1;
            return dp[ind1][ind2]=f(ind1,ind2-1,s1,s2,dp);
        }
        if(ind2==0){
            if(s1[ind1]==s2[ind2]) return 1;
            return dp[ind1][ind2]=f(ind1-1,ind2,s1,s2,dp);
        }
        if(s1[ind1]==s2[ind2]){
            return dp[ind1][ind2]=1+f(ind1-1,ind2-1,s1,s2,dp);
        }
        else{
            int one=f(ind1-1,ind2,s1,s2,dp);
            int two=f(ind1,ind2-1,s1,s2,dp);
            return dp[ind1][ind2]=max(one,two);
        }
        return dp[ind1][ind2]=0;
    }
    int longestCommonSubsequence(string s1, string s2) {
        n1=s1.size();n2=s2.size();
        vector<vector<int>>dp(n1,vector<int>(n2,-1)); //ind1,ind2 are the two states
        return f(n1-1,n2-1,s1,s2,dp);
    }
};