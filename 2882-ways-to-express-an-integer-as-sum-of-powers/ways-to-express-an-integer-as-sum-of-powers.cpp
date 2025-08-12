class Solution {
public:
    //Tabulation-2D (bina binary exponentiation ke ni hoga)
    const int M=1e9+7;
    //Binary exponentiation template (CP template se uthaya)
    int power(long long base,long long exp){
        long long res=1;
        while(exp>0){
            if(exp&1) res=(res*base)%M;
            exp=exp>>1;
            base=(base*base)%M;
        }
        return (int)res;
    }
    int numberOfWays(int n, int x) {
        vector<int> pows; 
        for (int i = 1;; i++) {
            long long val = power(i, x);
            if (val > n) break;
            pows.push_back((int)val);
        }
        int m=pows.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0)); //{curr,target}
        for(int curr=0;curr<=m;curr++){
            dp[curr][0]=1;
        }
        for(int i=m-1;i>=0;i--){
            for(int target=0;target<=n;target++){
                //not take
                dp[i][target]=dp[i+1][target];
                //take current number
                if(target>=pows[i]){
                    dp[i][target]=(dp[i][target]+dp[i+1][target-pows[i]])%M;
                }
            }
        }
        return dp[0][n];
    }
};