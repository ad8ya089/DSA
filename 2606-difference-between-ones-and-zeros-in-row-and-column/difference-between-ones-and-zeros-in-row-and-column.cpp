class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<int> row(m),col(n); // row-> uss row mei bas no. of ones store kr;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                row[i]+=grid[i][j];
                col[j]+=grid[i][j];
            }
        }
        //no. of zeroes=m-row[i],n-col[j];
        //tot= row[i]+col[j]-(m-n-row[i]-col[j])= 2*(row[i]+col[j])-m-n
        vector<vector<int>>diff(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                diff[i][j]=2*(row[i]+col[j])-m-n;
            }
        }
        return diff;
    }
};