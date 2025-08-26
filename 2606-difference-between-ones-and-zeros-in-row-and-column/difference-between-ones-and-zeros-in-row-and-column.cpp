class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<pair<int,int>> row(m),col(n); // row-> uss row mei {zero,one};
        for(int i=0;i<m;i++){
            int zero=0,one=0;
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) one++;
                else zero++;
            }
            row[i]={zero,one};
        }
        for(int j=0;j<n;j++){
            int zero=0,one=0;
            for(int i=0;i<m;i++){
                if(grid[i][j]==1) one++;
                else zero++;
            }
            col[j]={zero,one};
        }
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=row[i].second+col[j].second-row[i].first-col[j].first;
            }
        }
        return diff;
    }
};