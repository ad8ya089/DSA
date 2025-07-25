class Solution {
public:
    //Tabulation
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,1e9));
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) dp[0][target]=target/coins[0];
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int take=1e9;
                if(target>=coins[ind]) take=1+dp[ind][target-coins[ind]];
                int notTake=dp[ind-1][target];
                dp[ind][target]=min(take,notTake);
            }
        }
        int ans=dp[n-1][amount];
        if(ans==1e9) return -1;
        return ans;
    }
};