class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        using T=tuple<int,int,int>;
        priority_queue<T,vector<T>,greater<T>>pq;
        vector<vector<int>>time(n,vector<int>(n,INT_MAX));
        vector<vector<bool>>vis(n,vector<bool>(n,false));
        pq.emplace(grid[0][0],0,0);
        time[0][0]=grid[0][0]; //start
        vis[0][0]=1;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!pq.empty()){
            auto [t,r,c]=pq.top();pq.pop();
            if(t>time[r][c]) continue;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nc>=0 and nr<n and nc<n and !vis[nr][nc]){
                    int nextT=max(t,grid[nr][nc]);
                    if(nextT<time[nr][nc]){
                        time[nr][nc]=nextT;
                        pq.emplace(nextT,nr,nc);
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        return time[n-1][n-1];
    }
};