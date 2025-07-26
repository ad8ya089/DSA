class Solution {
public:
    //Tabulation O(NxK)
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int transac=2*k-1;transac>=0;transac--){
                if(transac%2==0){ //Buy
                    int buy=-prices[ind]+dp[ind+1][transac+1];
                    int notBuy=0+dp[ind+1][transac];
                    dp[ind][transac]=max(buy,notBuy);
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