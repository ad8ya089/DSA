class Solution {
public:
    //Djikstra dikhra mujhe --> min steps --> O((m*n*k log(m*n*k)))
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        //min heap : (steps,x,y,rem_k)
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;
        //dist : (x,y,rem_k)
        vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(k+1,INT_MAX)));
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        pq.emplace(0,0,0,k);
        dist[0][0][k]=0;
        while(!pq.empty()){
            auto [currS,x,y,rem_k]=pq.top();pq.pop();
            if(x==m-1 and y==n-1) return currS;
            if(currS>dist[x][y][rem_k]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextRem=rem_k-(grid[nx][ny]);
                if(nextRem<0) continue;
                int nextS=currS+1;
                if(nextS<dist[nx][ny][nextRem]){
                    dist[nx][ny][nextRem]=nextS;
                    pq.emplace(nextS,nx,ny,nextRem);
                }
            }
        }
        return -1;
    }
};