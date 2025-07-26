class Solution {
public:
    int maxProfit(vector<int>& prices,int fee) {
        //Space Optimisation using 4 variables --> O(Nx2) and O(4)
        int n=prices.size();
        int aheadBuy,aheadNotBuy,currBuy,currNotBuy;
        aheadNotBuy=0,aheadBuy=0;
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy){
                    int take=-prices[ind]+aheadNotBuy;
                    int notTake=0+aheadBuy;
                    currBuy=max(take,notTake);
                }
                else{
                    int sell=prices[ind]-fee+aheadBuy;
                    int notSell=0+aheadNotBuy;
                    currNotBuy=max(sell,notSell);
                }
            }
            aheadBuy=currBuy;
            aheadNotBuy=currNotBuy;
        }
        return aheadBuy;
    }
};