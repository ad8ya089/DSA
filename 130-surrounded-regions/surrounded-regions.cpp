class Solution {
public:
    vector<int>dr={-1,0,0,1};
    vector<int>dc={0,-1,1,0};
    int m,n;
    void dfs(int r,int c,vector<vector<char>>&board,vector<vector<bool>>&vis){
        vis[r][c]=true;
        for(int k=0;k<4;k++){
            int nr=r+dr[k];
            int nc=c+dc[k];
            if(nr>=0 and nr<m and nc>=0 and nc<n and !vis[nr][nc] and board[nr][nc]=='O'){
                dfs(nr,nc,board,vis);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        m=board.size();n=board[0].size();
        vector<vector<bool>>vis(m,vector<bool>(n,false));
        //yehi soch rha hu ki boundary wale 'O' se jo bhi 'O' connected honge voh sb toh surrounded ni hai baaki sab hai
        for(int i=0;i<m;i++){
            if(board[i][0]=='O'){
                dfs(i,0,board,vis);
            }
            if(board[i][n-1]=='O'){
                dfs(i,n-1,board,vis);
            }
        }
        for(int j=0;j<n;j++){
            if(board[0][j]=='O'){
                dfs(0,j,board,vis);
            }
            if(board[m-1][j]=='O'){
                dfs(m-1,j,board,vis);
            }
        }
        for(int i=1;i<m-1;i++){
            for(int j=1;j<n-1;j++){
                if(!vis[i][j] and board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};