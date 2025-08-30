class Solution {
public:
    bool validRow(vector<vector<char>>& mat){
        unordered_map<int,int>mp;
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(mat[i][j]!='.') mp[mat[i][j]]++;
                if(mp[mat[i][j]]>1) return false;
            }
            if(mp.size()!=0) mp.clear();
        }
        return true;
    }
    bool validCol(vector<vector<char>>& mat){
        unordered_map<int,int>mp;
        for(int j=0;j<9;j++){
            for(int i=0;i<9;i++){
                if(mat[i][j]!='.') mp[mat[i][j]]++;
                if(mp[mat[i][j]]>1) return false;
            }
            if(mp.size()!=0) mp.clear();
        }
        return true;
    }
    bool validBox(vector<vector<char>>& mat){
        unordered_map<int,int>mp;
        for(int stRow=0;stRow<9;stRow+=3){
            for(int stCol=0;stCol<9;stCol+=3){
                for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                        if(mat[stRow+i][stCol+j]!='.') mp[mat[stRow+i][stCol+j]]++;
                        if(mp[mat[stRow+i][stCol+j]]>1) return false;
                    }
                }
                if(mp.size()!=0) mp.clear();
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row=validRow(board);
        bool col=validCol(board);
        bool box=validBox(board);
        return row and col and box;
    }
};