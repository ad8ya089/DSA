class Solution {
public:
    vector<int> findP(int n){
        vector<int>v;
        for(;n>0;n/=2) v.push_back(n);
        return v;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans;
        for(auto q:queries){
            vector<int>p1=findP(q[0]),p2=findP(q[1]);
            while(!p1.empty() and !p2.empty() and p1.back()==p2.back()){
                p1.pop_back();p2.pop_back();
            }
            ans.push_back(1+p1.size()+p2.size());
        }
        return ans;
    }
};