class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int m=moveTime.size(),n=moveTime[0].size();
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        vector<vector<int>>time(m,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.emplace(0,0,0);
        time[0][0]=0;
        while(!pq.empty()){
            auto [currT,x,y]=pq.top();pq.pop();
            if(currT>time[x][y]) continue;
            for(int dir=0;dir<4;dir++){
                int nx=x+dx[dir],ny=y+dy[dir];
                if(nx<0 or ny<0 or nx>=m or ny>=n) continue;
                int nextT=max(currT,moveTime[nx][ny])+1; //ya toh currT pe hoga ya moveTime wale time pe
                if(nextT<time[nx][ny]){
                    time[nx][ny]=nextT;
                    pq.emplace(nextT,nx,ny);
                }
            }
        }
        return time[m-1][n-1];
    }
};