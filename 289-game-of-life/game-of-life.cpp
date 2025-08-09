class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>>grid=board;
        vector<int>dr={-1,-1,-1,0,0,1,1,1};
        vector<int>dc={-1,1,0,-1,1,-1,1,0};
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int live=0,dead=0;
                for(int k=0;k<8;k++){
                    int nr=i+dr[k];
                    int nc=j+dc[k];
                    if(nr>=0 and nr<m and nc>=0 and nc<n and board[nr][nc]==1){
                        live++;
                    }
                }
                if(grid[i][j]==1){
                    if(live<2 or live>3) grid[i][j]=0;
                }
                else{
                    if(live==3) grid[i][j]=1;
                }
            }
        }
        board=grid;
    }
};