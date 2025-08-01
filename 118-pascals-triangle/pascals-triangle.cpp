class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
        ans.push_back({1});
        int sz=1;
        for(int i=1;i<numRows;i++){
            vector<int>v;
            v.push_back(1);
            for(int j=0;j+1<sz;j++){
                int add=ans.back()[j]+ans.back()[j+1];
                v.push_back(add);
            }
            sz++;
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};