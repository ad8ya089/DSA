class Solution {
public:
    const int M=1e9+7;
    vector<int>binR(int n){
        int ct=0;
        vector<int>p;
        while(n){
            if(n%2==1) p.push_back(1<<ct);
            ct++;
            n/=2;
        }
        return p;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers=binR(n);
        vector<int>ans;
        for(int i=0;i<queries.size();i++){
            int start=queries[i][0],end=queries[i][1];
            long long mul=1;
            for(int j=start;j<=end;j++){
                mul=(mul*powers[j]%M)%M;
            }
            ans.push_back(mul);
        }
        return ans;
    }
};