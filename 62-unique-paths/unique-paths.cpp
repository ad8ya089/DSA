class Solution {
public:
    //Tabulation - space optimised using prev row
    int uniquePaths(int m, int n) {
        vector<int>prev(n,0);
        for(int r=0;r<m;r++){
            vector<int>curr(n,0);
            for(int c=0;c<n;c++){
                if(r==0 and c==0) curr[c]=1;
                else{
                    int left=0,up=0;
                    if(c-1>=0) left=curr[c-1];
                    if(r-1>=0) up=prev[c];
                    curr[c]=left+up;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};