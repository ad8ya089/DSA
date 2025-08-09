class Solution {
public:
    int m,n;
    int bfs(int row,int col,vector<vector<int>>& grid,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({row,col});
        vis[row][col]=1;
        int ct=0;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty()){
            auto it=q.front();q.pop();
            int r=it.first,c=it.second;
            ct++;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and grid[nr][nc]==1){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
        return ct;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m=grid.size();n=grid[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] and grid[i][j]==1){
                    ans=max(ans,bfs(i,j,grid,vis));
                }
            }
        }
        return ans;
    }
};