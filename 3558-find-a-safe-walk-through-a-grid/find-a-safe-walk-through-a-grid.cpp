class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m=grid.size(),n=grid[0].size();
        //max heap
        priority_queue<tuple<int,int,int>>pq;
        vector<vector<int>>h(m,vector<int>(n,INT_MIN));
        pq.emplace(health-(grid[0][0]==1),0,0);
        h[0][0]=health-(grid[0][0]==1);
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        while(!pq.empty()){
            auto [currH,x,y]=pq.top();pq.pop();
            if(currH<h[x][y]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextH=currH-(grid[nx][ny]==1);
                if(nextH>h[nx][ny]){
                    h[nx][ny]=nextH;
                    pq.emplace(nextH,nx,ny);
                }
            }
        }
        cout<<h[m-1][n-1];
        return (h[m-1][n-1]>=1);
    }
};