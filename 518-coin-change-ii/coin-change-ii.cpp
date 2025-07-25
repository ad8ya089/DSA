class Solution {
public:
    //Tabulation
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<long>prev(amount+1,0);
        for(int target=0;target<=amount;target++){
            if(target%coins[0]==0) prev[target]=1;
        }
        for(int ind=1;ind<n;ind++){
            vector<long>curr(amount+1,0);
            for(int target=0;target<=amount;target++){
                int notTake=prev[target];
                int take=0;
                if(target>=coins[ind]) take=curr[target-coins[ind]]; //take krne ke baad bhi same index pe reh laadle
                curr[target]=(long)take+notTake;
            }
            prev=curr;
        }
        return prev[amount];
    }
};