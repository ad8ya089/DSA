class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Tabulation O(Nx4)
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(5,0));
        for(int i=0;i<=4;i++) dp[n][i]=0;
        for(int i=0;i<=n;i++) dp[i][4]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int transac=3;transac>=0;transac--){
                if(transac%2==0){//Buy
                    int take=-prices[ind]+dp[ind+1][transac+1];
                    int notTake=0+dp[ind+1][transac];
                    dp[ind][transac]=max(take,notTake);
                }
                else{ //Sell
                    int sell=prices[ind]+dp[ind+1][transac+1];
                    int notSell=0+dp[ind+1][transac];
                    dp[ind][transac]=max(sell,notSell);
                }
            }
        }
        return dp[0][0];
    }
};