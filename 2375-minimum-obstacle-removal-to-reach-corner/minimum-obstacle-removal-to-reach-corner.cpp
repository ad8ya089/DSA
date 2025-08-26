class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        //minheap
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        pq.emplace(0,0,0);
        cost[0][0]=0;
        while(!pq.empty()){
            auto [currCost,x,y]=pq.top();pq.pop();
            if(currCost>cost[x][y]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k];
                int ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextCost=currCost+grid[x][y];
                if(nextCost<cost[nx][ny]){
                    cost[nx][ny]=nextCost;
                    pq.emplace(nextCost,nx,ny);
                }
            }
        }
        return cost[m-1][n-1];
    }
};