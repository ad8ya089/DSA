class Solution {
public: 
    //Bottom Up
    int maximumLength(vector<int>& nums,int k) {
        int n=nums.size();
        int ans=0;
        vector<vector<int>>dp(k,vector<int>(n,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                int mod=(nums[i]+nums[j])%k;
                dp[mod][i]=max(dp[mod][i],dp[mod][j]+1);
                ans=max(ans,dp[mod][i]);
            }
        }
        return ans;
    }
};