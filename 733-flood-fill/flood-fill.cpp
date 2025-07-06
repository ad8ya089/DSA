class Solution {
public:
    void bfs(int row,int col,vector<vector<int>>& image,int color,vector<vector<bool>>&vis){
        int m=image.size(),n=image[0].size();
        queue<pair<int,int>>q;
        int orig=image[row][col];
        q.push({row,col});
        vis[row][col]=1;
        image[row][col]=color;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty()){
            auto it=q.front();q.pop();
            int r=it.first;
            int c=it.second;
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and image[nr][nc]==orig){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                    image[nr][nc]=color;
                }
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m=image.size(),n=image[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        bfs(sr,sc,image,color,vis);
        return image;
    }
};