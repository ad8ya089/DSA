class Solution {
public:
    //Djikstra + thoda sa bitmasking O(mxnx2^k log(m⋅n⋅2k)) --> BFS se bhi kr skte(less complexity bhi hoga log wala term ni aaega that's it)
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        //min heap (steps,x,y,keys)
        priority_queue<tuple<int,int,int,int>,vector<tuple<int,int,int,int>>,greater<tuple<int,int,int,int>>>pq;
        int stX=-1,stY=-1;
        int totK=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=grid[i][j];
                if(ch=='@'){
                    stX=i;stY=j;
                }
                if(ch>='a' and ch<='z'){
                    totK=max(totK,ch-'a'+1); //bitmasking ke liye kitna max chahiye
                }
            }
        }
        
        int finalMask=(1<<totK)-1; //sb key collect krliye
        vector<vector<vector<int>>>dist(m,vector<vector<int>>(n,vector<int>(1<<totK,INT_MAX)));
        pq.emplace(0,stX,stY,0);
        dist[stX][stY][0]=0;
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};

        while(!pq.empty()){
            auto[steps,x,y,mask]=pq.top();pq.pop();
            if(mask==finalMask) return steps;
            if(steps>dist[x][y][mask]) continue;
            for(int k=0;k<4;k++){
                int nx=x+dx[k],ny=y+dy[k];
                if(nx<0 or nx>=m or ny<0 or ny>=n) continue;
                char c=grid[nx][ny];
                if(c=='#') continue;
                int newMask=mask;
                if(c>='A' and c<='F'){
                    bool keyExist=(mask&(1<<(c-'A')));
                    if(!keyExist) continue;
                }
                if(c>='a' and c<='f'){
                    newMask|=(1<<(c-'a'));
                }
                if(steps+1<dist[nx][ny][newMask]){
                    dist[nx][ny][newMask]=steps+1;
                    pq.emplace(steps+1,nx,ny,newMask);
                }
            }
        }
        return -1;
    }
};