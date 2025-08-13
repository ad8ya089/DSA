class Solution {
public:
    int m,n;
    void bfs(int row,int col,set<pair<int,int>>&st,vector<vector<int>>& heights,vector<vector<bool>>&vis){
        queue<pair<int,int>>q;
        q.push({row,col});
        vector<int>dr={-1,0,0,1};
        vector<int>dc={0,-1,1,0};
        while(!q.empty()){
            auto it=q.front();q.pop();
            int r=it.first,c=it.second;
            st.insert({r,c});
            for(int i=0;i<4;i++){
                int nr=r+dr[i];
                int nc=c+dc[i];
                if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and heights[nr][nc]>=heights[r][c]){
                    q.push({nr,nc});
                    vis[nr][nc]=1;
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m=heights.size();n=heights[0].size();
        set<pair<int,int>>pac,atl;
        vector<vector<bool>>vis1(m,vector<bool>(n,false));
        vector<vector<bool>>vis2(m,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            bfs(0,i,pac,heights,vis1);
        }
        for(int i=0;i<m;i++){
            bfs(i,0,pac,heights,vis1);
        }
        for(int i=0;i<n;i++){
            bfs(m-1,i,atl,heights,vis2);
        }
        for(int i=0;i<m;i++){
            bfs(i,n-1,atl,heights,vis2);
        }
        vector<vector<int>>ans;
        for(auto it:pac){
            if(atl.count(it)){
                ans.push_back({it.first,it.second});
            }
        }
        return ans;
    }
};