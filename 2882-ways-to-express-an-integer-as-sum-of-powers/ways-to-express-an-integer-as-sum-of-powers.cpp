class Solution {
public:
    //Bhai memo kaafi hai yeh sb bakchodi hai
    //Tabulation-1D (bina binary exponentiation ke ni hoga)
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
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;;i++){
            long long val=power(i,x);
            if(val>n) break;
            for(int j=n;j>=val;j--){
                dp[j]=(dp[j]+dp[j-val])%M;
            }
        }
        return dp[n];
    }
};