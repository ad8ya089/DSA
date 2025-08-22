class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        int mnR=1001,mnC=1001,mxR=-1,mxC=-1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    mnR=min(mnR,i);
                    mxR=max(mxR,i);
                    mnC=min(mnC,j);
                    mxC=max(mxC,j);
                }
            }
        }
        return (mxR-mnR+1)*(mxC-mnC+1);
    }
};