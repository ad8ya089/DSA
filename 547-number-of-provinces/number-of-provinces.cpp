class Solution {
public:
    void dfs(vector<vector<int>>&adj,int node,vector<bool>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]) dfs(adj,it,vis);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j and isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool>vis(n);
        int ct=0;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                ct++;
                dfs(adj,i,vis);
            }
        }
        return ct;
    }
};