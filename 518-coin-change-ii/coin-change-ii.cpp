class Solution {
public:
    //Tabulation
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<long>>dp(n,vector<long>(amount+1,0));
        for(int ind=0;ind<n;ind++){
            dp[ind][0]=1;
        }
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) dp[0][target]=1;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=1;target<=amount;target++){
                int notTake=dp[ind-1][target];
                int take=0;
                if(target>=coins[ind]) take=dp[ind][target-coins[ind]]; //take krne ke baad bhi same index pe reh laadle
                dp[ind][target]=(long)take+notTake;
            }
        }
        return dp[n-1][amount];
    }
};