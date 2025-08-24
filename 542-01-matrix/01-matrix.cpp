class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                    ans[i][j]=0;
                }
            }
        }
        int dist=1;
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int r=q.front().first,c=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int nr=r+dr[k];
                    int nc=c+dc[k];
                    if(nr>=0 and nr<n and nc>=0 and nc<m and !vis[nr][nc] and mat[nr][nc]!=0){
                        vis[nr][nc]=1;
                        q.push({nr,nc});
                        ans[nr][nc]=min(ans[nr][nc],dist);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};