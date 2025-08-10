class Solution {
public:
    //Tabulation with space optimisation (1 array)
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>curr(n+1,0);
        int ans=0,prevDiag;
        for(int i=1;i<=m;i++){
            prevDiag=0; //store dp[i-1][j-1] from prev row
            for(int j=1;j<=n;j++){
                int temp=curr[j];
                if(mat[i-1][j-1]=='1'){
                    curr[j]=min({curr[j],curr[j-1],prevDiag})+1;
                    ans=max(ans,curr[j]);
                }
                else{
                    curr[j]=0;
                }
                prevDiag=temp; //move diag for next col
            };
        }
        return ans*ans;       
    }
};