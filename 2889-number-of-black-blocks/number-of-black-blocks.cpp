class Solution {
public:
    long long encode(int r,int c){
        return ((long long)r<<32) | (unsigned int)c;
    }
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coord) {
        unordered_map<long long,int>sub;
        vector<long long>ans(5);
        long long tot=1LL*(m-1)*(n-1); //no of 2x2 submatrix nikal le
        for(auto it:coord){
            int r=it[0],c=it[1];
            vector<pair<int,int>> v={{r,c},{r,c-1},{r-1,c},{r-1,c-1}};
            for(int i=0;i<4;i++){
                int rr=v[i].first,cc=v[i].second;
                if(rr>=0 and cc>=0 and rr<m-1 and cc<n-1){
                    sub[encode(rr,cc)]++;
                }
            }
        }
        for(auto it:sub){
            ans[it.second]++;
        }
        ans[0]=tot-ans[1]-ans[2]-ans[3]-ans[4];
        return ans;
    }
};