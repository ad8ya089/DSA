class Solution {
public:
    //better way to calculate binary representation
    const int M=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers;
        for(int i=0;i<32;i++){
            if((n&(1<<i))!=0){ //ith bit is set
                powers.push_back(1<<i);
            }
        }
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