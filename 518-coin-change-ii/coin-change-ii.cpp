class Solution {
public:
    //Tabulation with space optimisation to 1 array only
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long>prev(amount+1,0);
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=1;
        }
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=amount;target++){
                int notTake=prev[target];
                int take=0;
                if(target>=coins[ind]) take=prev[target-coins[ind]]; //take krne ke baad bhi same index pe reh laadle
                prev[target]=(long)take+notTake;
            }
        }
        return prev[amount];
    }
};