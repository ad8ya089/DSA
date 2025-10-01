class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int q=queries.size();
        vector<int>color(n);
        vector<int>ans(q);
        ans[0]=0;
        color[queries[0][0]]=queries[0][1];
        for(int i=1;i<q;i++){
            int ind=queries[i][0],colNew=queries[i][1],colOrig=color[ind];
            ans[i]=ans[i-1];
            if(ind-1>=0 and color[ind-1]==colOrig and colOrig!=0) ans[i]--;
            if(ind+1<n and color[ind+1]==colOrig  and colOrig!=0) ans[i]--;
            color[ind]=colNew;
            if(ind-1>=0 and color[ind-1]==colNew and colNew!=0) ans[i]++;
            if(ind+1<n and color[ind+1]==colNew and colNew!=0) ans[i]++;
        }
        return ans;
    }
};