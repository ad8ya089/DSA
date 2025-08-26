class Solution {
public:
    //djikstra se toh hogya ab dequeue se krle (0-1 BFS)
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int>dx={0,0,1,-1};
        vector<int>dy={1,-1,0,0};
        vector<vector<int>>cost(m,vector<int>(n,INT_MAX));
        //Deque
        deque<pair<int,int>>dq;
        dq.emplace_front(0,0);
        cost[0][0]=0;
        while(!dq.empty()){
            auto [x,y]=dq.front();dq.pop_front();
            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir];
                int ny=y+dy[dir];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextCost=cost[x][y] +(dir!=grid[x][y]-1);
                if(nextCost<cost[nx][ny]){
                    cost[nx][ny]=nextCost;
                    if(dir==grid[x][y]-1){
                        dq.emplace_front(nx,ny); // 0-cost edge
                    }
                    else{
                        dq.emplace_back(nx,ny);
                    }
                }
            } 
        }
        return cost[m-1][n-1];
    }
};