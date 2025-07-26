class Solution {
public:
    //Tabulation with space optimisation
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>ahead(2,vector<int>(3,0));
        vector<vector<int>>curr(2,vector<int>(3,0));
        //(N+1)x2x3 buy-->1, sell->0 , N+1 to incorporate ind==n case in tabulation
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=2;cap>=1;cap--){
                    if(buy){
                        int take=-prices[ind]+ahead[0][cap];
                        int notTake=0+ahead[1][cap];
                        curr[buy][cap]=max(take,notTake);
                    }
                    else{
                        int sell=prices[ind]+ahead[1][cap-1];
                        int notSell=0+ahead[0][cap];
                        curr[buy][cap]=max(sell,notSell);
                    }
                }
            }
            ahead=curr;
        }
        return ahead[1][2];
    }
};