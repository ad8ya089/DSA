class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size(),m=mat[0].size();
        vector<vector<int>> ans(n,vector<int>(m,INT_MAX));
        queue<pair<pair<int,int>,int>>q;
        vector<vector<bool>>vis(n,vector<bool>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty())
        {
            auto it=q.front();
            q.pop();
            int x=it.first.first;
            int y=it.first.second;
            int d=it.second;
            for(int k=0;k<4;k++)
            {
                int nr=x+dr[k];
                int nc=y+dc[k];
                if(nr>=0 and nc>=0 and nr<n and nc<m  and mat[nr][nc]==1)
                {
                    if(ans[nr][nc]>(d+1))
                    {
                        q.push({{nr,nc},d+1});
                        ans[nr][nc]=min(ans[nr][nc],d+1);

                    }
                    
                    
                }
            }


        }
        return ans;
    }
};