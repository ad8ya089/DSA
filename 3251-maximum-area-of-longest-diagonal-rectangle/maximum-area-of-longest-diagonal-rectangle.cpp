class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        double mxDiag=0;
        int mx=0;
        for(int i=0;i<n;i++){
            int l=dimensions[i][0];
            int w=dimensions[i][1];
            double diag=sqrt(l*l+w*w);
            if(diag>mxDiag){
                mxDiag=diag;
                mx=l*w;
            }
            if(diag==mxDiag){
                mx=max(mx,l*w);
            }
        }
        return mx;
    }
};