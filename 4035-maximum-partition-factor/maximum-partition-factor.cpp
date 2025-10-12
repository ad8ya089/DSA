class Solution {
public:
    bool pos(vector<vector<int>>&points,int pf){
        int n=points.size();
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                if(dist<pf){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        //Bipartite check
        vector<int>color(n,-1);
        for(int col=0;col<n;col++){
            if(color[col]!=-1) continue;
            //BFS from col
            queue<int>q;
            q.push(col);
            color[col]=0;
            while(!q.empty()){
                int u=q.front();q.pop();
                for(int v:adj[u]){
                    if(color[v]==-1){
                        color[v]=color[u]^1;
                        q.push(v);
                    }
                    else{
                        if(color[v]==color[u]){
                            return false;
                        }
                    }
                }  
            }       
        }
        return true;
    }
    int maxPartitionFactor(vector<vector<int>>& points) {
        int n=points.size();
        if(n==2) return 0;
        int l=0,r=4e8; //-1e8 se 1e8 --> 2 baar (x aur y ka abs diff)
        int ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(pos(points,mid)){
                l=mid+1;
                ans=mid;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};