class Solution {
public:
    //Tabulation with space optimisation (2 array)
    int maximalSquare(vector<vector<char>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>prev(n+1,0),curr(n+1,0);
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(mat[i-1][j-1]=='1'){
                    curr[j]=min({prev[j],curr[j-1],prev[j-1]})+1;
                    ans=max(ans,curr[j]);
                }
                else{
                    curr[j]=0;
                }
            }
            prev=curr;
        }
        return ans*ans;       
    }
};