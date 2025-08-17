class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n=prices.size();
        long long orig=0;
        for(int i=0;i<n;i++){
            orig+=1LL*prices[i]*strategy[i];
        }
        long long curr=orig;
        for(int i=0;i<k/2;i++){
            curr+=(0-strategy[i])*prices[i];
        }
        for(int i=k/2;i<k;i++){
            curr+=(1-strategy[i])*prices[i];
        }
        long long mx=max(orig,curr);
        for(int i=k;i<n;i++){
            int mid=i-k/2;
            curr+=(strategy[i-k]-0)*prices[i-k]; //previous element ko normal krdiye
            curr+=(1-strategy[i])*prices[i]; // naya element ko 1 bana diye
            curr+=(0-1)*prices[mid]; //bich wala element ko 1 se 0 bana do
            mx=max(mx,curr);
        }
        return mx;
    }
};