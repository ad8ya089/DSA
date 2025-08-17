class Solution {
public:
    const int M=1e9+7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int q=queries.size();
        for(int i=0;i<q;i++){
            int l=queries[i][0],r=queries[i][1],k=queries[i][2],v=queries[i][3];
            int idx=l;
            while(idx<=r){
                nums[idx]=(1LL*nums[idx]*v)%M;
                idx+=k;
            }
        }
        int xr=0;
        for(int i=0;i<nums.size();i++){
            xr^=nums[i];
        }
        return xr;
    }
};