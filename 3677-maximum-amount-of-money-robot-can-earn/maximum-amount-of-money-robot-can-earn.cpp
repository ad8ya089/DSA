class Solution {
public:
    //Memoization
    int m,n;
    int maximumAmount(vector<vector<int>>& coins) {
        m=coins.size();n=coins[0].size();
        vector<vector<vector<int>>>dp(m,vector<vector<int>>(n,vector<int>(3,INT_MIN)));
        for(int cap=0;cap<3;cap++){
            for(int r=m-1;r>=0;r--){
                for(int c=n-1;c>=0;c--){
                    if(r==m-1 and c==n-1){
                        if(cap>0 and coins[r][c]<0) dp[r][c][cap]=0;
                        else dp[r][c][cap]=coins[r][c];
                        continue;
                    }
                    int rightDo=INT_MIN,rightDont=INT_MIN,downDo=INT_MIN,downDont=INT_MIN;
                    if(c+1<n){
                        if(cap>0) rightDo=dp[r][c+1][cap-1];
                        //Option to skip the negative cell
                        rightDont=coins[r][c]+dp[r][c+1][cap];
                    }
                    if(r+1<m){
                        if(cap>0) downDo=dp[r+1][c][cap-1];
                        //Option to skip the negative cell
                        downDont=coins[r][c]+dp[r+1][c][cap];
                    }
                    dp[r][c][cap]=max(max(rightDo,rightDont),max(downDo,downDont));
                }
            }
        }
        return dp[0][0][2];
    }
};