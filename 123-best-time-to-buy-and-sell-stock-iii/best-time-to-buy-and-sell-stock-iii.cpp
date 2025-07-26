class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Space optimisation O(Nx4)
        int n=prices.size();
        vector<int>ahead(5,0),curr(5,0);
        for(int i=0;i<=4;i++) ahead[i]=0;
        curr[4]=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int transac=3;transac>=0;transac--){
                if(transac%2==0){//Buy
                    int take=-prices[ind]+ahead[transac+1];
                    int notTake=0+ahead[transac];
                    curr[transac]=max(take,notTake);
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