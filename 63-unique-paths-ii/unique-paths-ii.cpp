class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>prev(n,0);
        for(int r=0;r<m;r++){
            vector<int>curr(n,0);
            for(int c=0;c<n;c++){
                if(grid[r][c]==1) curr[c]=0;
                else if(r==0 and c==0) curr[c]=1;
                else{
                    int left=0,up=0;
                    if(c-1>=0) left=curr[c-1];
                    if(r-1>=0) up=prev[c];
                    curr[c]=left+up;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};