class Solution {
public:
    //Tabulation with space optimisation
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<int>ahead(2*k+1,0),curr(2*k+1,0);
        for(int ind=n-1;ind>=0;ind--){
            for(int transac=2*k-1;transac>=0;transac--){
                if(transac%2==0){ //Buy
                    int buy=-prices[ind]+ahead[transac+1];
                    int notBuy=0+ahead[transac];
                    curr[transac]=max(buy,notBuy);
                }
                else{ //Sell
                    int sell=prices[ind]+ahead[transac+1];
                    int notSell=0+ahead[transac];
                    curr[transac]=max(sell,notSell);
                }
            }
            ahead=curr;
        }
        return ahead[0];
    }
};