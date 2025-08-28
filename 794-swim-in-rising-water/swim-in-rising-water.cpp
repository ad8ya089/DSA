class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        //min heap (time,x,y)
        using State=tuple<int,int,int>; //yeh naya chiz sikha bc
        priority_queue<State,vector<State>,greater<State>>pq;
        vector<vector<int>>time(n,vector<int>(n,INT_MAX));
        pq.emplace(grid[0][0],0,0);
        time[0][0]=grid[0][0]; //shuru toh first time se hi hoga na
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        while(!pq.empty()){
            auto [t,x,y]=pq.top();pq.pop();
            if(t>time[x][y]) continue; //faltu
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=n or ny<0 or ny>=n) continue;
                int nextT=max(t,grid[nx][ny]); //max height jo laga hai abhi tk to reach (nx,ny) --> issi ko toh minimise krna hai bhai
                if(nextT<time[nx][ny]){
                    time[nx][ny]=nextT;
                    pq.emplace(nextT,nx,ny);
                }
            }
        }
        return time[n-1][n-1];
    }
};