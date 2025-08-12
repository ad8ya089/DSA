class Solution {
public:
    //Memo(bina binary exponentiation ke ni hoga)
    vector<vector<int>>dp;
    int x;
    const int M=1e9+7;
    //Binary exponentiation template (CP template se uthaya)
    int power(long long x,long long y){
        int res=1;
        while(y>0){
            if(y&1) res=(res*x)%M;
            y=y>>1;
            x=(x*x)%M;
        }
        return res;
    }
    int f(int n,int curr){
        if(n==0) return 1;
        if(curr>n) return 0; //n<0 pe bhi
        if(dp[n][curr]!=-1) return dp[n][curr];
        int val=power(curr,x);
        if(val>n) return 0; //time ki bachat lol
        int take=0;
        if(n>=val) take=f(n-val,curr+1);
        int notTake=f(n,curr+1);
        return dp[n][curr]=(take+notTake)%M;
    }
    int numberOfWays(int n, int X) {
        x=X;
        dp=vector<vector<int>>(n+1,vector<int>(n+1,-1));
        return f(n,1);
    }
};