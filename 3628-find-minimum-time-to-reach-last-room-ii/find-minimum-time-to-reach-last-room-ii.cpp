class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size(),n=moveTime[0].size();
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        //min heap(time,x,y,jump)
        using State=tuple<int,int,int,int>;
        priority_queue<State,vector<State>,greater<State>>pq;
        vector<vector<int>>time(m,vector<int>(n,INT_MAX));
        pq.emplace(0,0,0,1);
        time[0][0]=0;
        while(!pq.empty()){
            auto [t,x,y,jump]=pq.top();pq.pop();
            if(t>time[x][y]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                //wait = max(0,moveTime[nx][ny]-t) and nextT=t+wait+1
                int nextT=max(t,moveTime[nx][ny])+jump;
                int newJump=(jump==1) ? 2 : 1;
                if(nextT<time[nx][ny]){
                    time[nx][ny]=nextT;
                    pq.emplace(nextT,nx,ny,newJump);
                } 
            }
        }
        return time[m-1][n-1];
    }
};