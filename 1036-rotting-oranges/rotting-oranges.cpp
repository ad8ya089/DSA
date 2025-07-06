class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>>vis(m,vector<int>(n,0));
        int ct=0,ct1=0;;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
                if(grid[i][j]==1) ct++;
            }
        }
        if(ct==0) return 0;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,1,-1,0};
        int ans=-1;
        while(!q.empty()){
            auto it=q.front();q.pop();
            int r=it.first.first;
            int c=it.first.second;
            int t=it.second;
            ans=max(ans,t);
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nc>=0 and nr<m and nc<n and vis[nr][nc]==0 and grid[nr][nc]==1){
                    vis[nr][nc]=1;
                    q.push({{nr,nc},t+1});
                    ct1++;
                }
            }
        }
        if(ct!=ct1) return -1;
        return ans;
    }
};