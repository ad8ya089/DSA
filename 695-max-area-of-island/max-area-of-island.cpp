class Solution {
public:
    int m,n;
    int dfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        if(row<0 or row>=m or col<0 or col>=n or vis[row][col] or grid[row][col]==0) return 0;
        vis[row][col]=1;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        int tot=0;
        for(int i=0;i<4;i++){
            int nr=row+dr[i];
            int nc=col+dc[i];
            tot+=dfs(nr,nc,grid,vis);
        }
        return 1+tot;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    ans=max(ans,dfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};