class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n=points.size();
        vector<vector<int>>ans;
        //max heap (minimum k elements chahiye isliye)
        priority_queue<pair<int,pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            int x=points[i][0],y=points[i][1];
            int dist=(x*x)+(y*y);
            pq.push({dist,{x,y}});
            if(pq.size()>k) pq.pop();
        }  
        while(!pq.empty()){
            auto it=pq.top();pq.pop();
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};