class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size(),m=grid[0].size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            priority_queue<int>rowPQ;
            for(int j=0;j<m;j++){
                rowPQ.push(grid[i][j]);
            }
            int mx=limits[i];
            while(mx-- and !rowPQ.empty()){
                pq.push(rowPQ.top());
                rowPQ.pop();
            }
        }
        long long sum=0;
        while(k--){
            sum+=pq.top();pq.pop();
        }
        return sum;
    }
};