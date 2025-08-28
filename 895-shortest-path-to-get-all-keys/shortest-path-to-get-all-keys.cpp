class Solution {
public:
    //BFS + thoda sa bitmasking O(mxnx2^k) --> Djikstra se bhi kr skte(more complexity -->ek log wala term aaega that's it) 
    //Imp note yaha djikstra ke jagah BFS isliye use kr paa rhe kyuki step 1-by-1 badh rha hai agar randomly increment hota toh djikstra would be better but kyuki yaha sirf 1 ka increment horha consistently along neighbours BFS better
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size(),n=grid[0].size();
        //queue (steps,x,y,keys)
        queue<tuple<int,int,int,int>>q;
        int stX=-1,stY=-1;
        int allMask=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch=grid[i][j];
                if(ch=='@'){
                    stX=i;stY=j;
                }
                if(ch>='a' and ch<='z'){
                    allMask|=(1<<(ch-'a'));
                }
            }
        }

        vector<vector<vector<bool>>>vis(m,vector<vector<bool>>(n,vector<bool>(64,false))); //2^6=64 ja skta max
        q.emplace(0,stX,stY,0);
        vis[stX][stY][0]=true;
        vector<int>dx={-1,0,0,1};
        vector<int>dy={0,-1,1,0};

        while(!q.empty()){
            auto[steps,x,y,mask]=q.front();q.pop();
            if(mask==allMask) return steps;
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
                    newMask|=(1<<(c-'a')); //pickup key
                }
                if(!vis[nx][ny][newMask]){
                    vis[nx][ny][newMask]=true;
                    q.emplace(steps+1,nx,ny,newMask);
                }
            }
        }
        return -1;
    }
};