class Solution {
public:
    //Tabulation
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        //(N+1)x2x3 buy-->1, sell->0 , N+1 to incorporate ind==n case in tabulation
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=2;cap>=1;cap--){
                    if(buy){
                        int take=-prices[ind]+dp[ind+1][0][cap];
                        int notTake=0+dp[ind+1][1][cap];
                        dp[ind][buy][cap]=max(take,notTake);
                    }
                    else{
                        int sell=prices[ind]+dp[ind+1][1][cap-1];
                        int notSell=0+dp[ind+1][0][cap];
                        dp[ind][buy][cap]=max(sell,notSell);
                    }
                }
            }
        }
        return dp[0][1][2];
    }
};