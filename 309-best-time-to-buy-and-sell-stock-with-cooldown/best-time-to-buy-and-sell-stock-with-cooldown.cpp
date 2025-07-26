class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //Space optimisation O(N) & O(6)
        int n=prices.size();
        vector<int>front1(2,0),front2(2,0),curr(2,0 );
        for(int ind=n-1;ind>=0;ind--){
            int take=-prices[ind]+front1[0];
            int notTake=0+front1[1];
            curr[1]=max(take,notTake);

            int sell=prices[ind]+front2[1];
            int notSell=0+front1[0];
            curr[0]=max(sell,notSell);

            front2=front1;
            front1=curr;
        }
        return front1[1];
    }
};