class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size(),n=heights[0].size();
        vector<vector<int>>effort(m,vector<int>(n,INT_MAX));
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<tuple<int,int,int>>>pq;
        pq.emplace(0,0,0);
        effort[0][0]=0;
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};
        while(!pq.empty()){
            auto [currE,x,y]=pq.top();pq.pop();
            if(currE>effort[x][y]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                int nextE=max(currE,abs(heights[nx][ny]-heights[x][y])); //max absolute difference jo abhi tak dikha hai vhi hoga next E
                if(nextE<effort[nx][ny]){
                    effort[nx][ny]=nextE;
                    pq.emplace(nextE,nx,ny);
                }
            }
        }
        return effort[m-1][n-1];
    }
};