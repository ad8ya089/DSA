class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int start=x,end=x+k-1;
        while(start<=end){
            for(int i=0;i<k;i++){
                swap(grid[start][y+i],grid[end][y+i]);
            }
            start++;end--;
        }
        return grid;
    }
};