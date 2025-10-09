class Solution {
public:
    const int M=1e9+7;
    vector<vector<int>>adj={{4,6} , {6,8} , {7,9} , {4,8} , {3,9,0} , {} ,     
                           {1,7,0} , {2,6} , {1,3} , {4,2}};
    int f(int left,int num,vector<vector<int>>&dp){
        if(left==0){
            return 1;
        }
        if(dp[left][num]!=-1) return dp[left][num];
        int ans=0;
        for(int &next:adj[num]){
            ans=(ans+f(left-1,next,dp))%M;
        }
        return dp[left][num]=ans;
    }
    int knightDialer(int n) {
        vector<vector<int>>dp(n,vector<int>(10,-1));
        int ans=0;
        for(int i=0;i<=9;i++){
            ans=(ans+f(n-1,i,dp))%M;
        }
        return ans;
    }
};