class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m>1 and n>1 and grid[0][1]>1 and grid[1][0]>1) return -1;
        vector<vector<int>>time(m,vector<int>(n,INT_MAX));
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        using State=tuple<int,int,int>;
        //min heap (time,x,y)
        priority_queue<State,vector<State>,greater<State>>pq;
        pq.emplace(0,0,0);
        time[0][0]=0;
        while(!pq.empty()){
            auto [t,x,y]=pq.top();pq.pop();
            if(x==m-1 and y==n-1) return time[m-1][n-1]; 
            if(t>time[x][y]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int wait=max(grid[nx][ny],t+1);
                if((wait-(t+1))%2==1) wait++;
                int nextT=wait;
                if(nextT<time[nx][ny]){
                    time[nx][ny]=nextT;
                    pq.emplace(nextT,nx,ny);
                }
            }
        }
        return -1;
    }
};