class Solution {
public:
    //BFS se bhi kr skte --> O(mxnxk)
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size(),n=grid[0].size();
        //(steps,x,y,rem_k)
        queue<tuple<int,int,int,int>>q;
        //vis : (x,y,rem_k)
        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(k+1,false)));
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        q.emplace(0,0,0,k);
        vis[0][0][k]=true;
        while(!q.empty()){
            auto [steps,x,y,rem_k]=q.front();q.pop();
            if(x==m-1 and y==n-1) return steps;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextRem=rem_k-(grid[nx][ny]);
                if(nextRem<0) continue;
                if(!vis[nx][ny][nextRem]){
                    vis[nx][ny][nextRem]=1;
                    q.emplace(steps+1,nx,ny,nextRem);
                }
            }
        }
        return -1;
    }
};