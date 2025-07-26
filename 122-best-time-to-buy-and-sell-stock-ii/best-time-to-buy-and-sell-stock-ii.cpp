class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn=INT_MAX,ans=0;
        for(int i=0;i<prices.size();i++){
            if(prices[i]>mn){
                ans+=prices[i]-mn;//sell krdiya
                mn=prices[i];
                continue;
            }
            mn=min(mn,prices[i]);
        }
        return ans;
    }
};