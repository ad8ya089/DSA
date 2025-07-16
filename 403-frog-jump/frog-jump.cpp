class Solution {
public:
    int n;
    unordered_map<int,int>mp;
    bool f(vector<int>stones,int curr_ind,int prevJump,vector<vector<int>>&dp){
        if(curr_ind==n-1) return true;
        bool ans=false;
        if(dp[curr_ind][prevJump]!=-1){
            return dp[curr_ind][prevJump];
        }
        for(int nextJump=prevJump-1;nextJump<=prevJump+1;nextJump++){
            if(nextJump<=0) continue;
            int nextStone=stones[curr_ind]+nextJump;
            if(mp.find(nextStone)!=mp.end()){
                ans = ans || f(stones,mp[nextStone],nextJump,dp);
            }
        } 
        return dp[curr_ind][prevJump]=ans;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        if(stones[1]-stones[0]!=1) return false;
        vector<vector<int>>dp(n,vector<int>(n,-1)); //dp[ind][diff]
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        return f(stones,0,0,dp);
    }
};