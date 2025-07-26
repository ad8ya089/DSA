class Solution {
public:
    //Memoization O(NxK)
    int n,k;
    int f(int ind,int transac,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==n or transac==2*k) return 0;
        if(dp[ind][transac]!=-1) return dp[ind][transac];
        if(transac%2==0){ //Buy
            int buy=-prices[ind]+f(ind+1,transac+1,prices,dp);
            int notBuy=0+f(ind+1,transac,prices,dp);
            return dp[ind][transac]=max(buy,notBuy);
        }
        else{ //Sell
            int sell=prices[ind]+f(ind+1,transac+1,prices,dp);
            int notSell=0+f(ind+1,transac,prices,dp);
            return dp[ind][transac]=max(sell,notSell);
        }
    }
    int maxProfit(int K, vector<int>& prices) {
        k=K;
        n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2*k+1,-1));
        return f(0,0,prices,dp);
    }
};