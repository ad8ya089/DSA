class Solution {
public: 
    int n;
    int f(int ind,vector<int>& energy, int k,vector<int>&dp){
        if(ind>=n) return 0;
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=f(ind+k,energy,k,dp)+energy[ind];
    }
    int maximumEnergy(vector<int>& energy, int k) {
        n=energy.size();
        int ans=INT_MIN;
        vector<int>dp(n,-1);
        for(int i=0;i<n;i++){
            ans=max(ans,f(i,energy,k,dp));
        }
        return ans;
    }
};