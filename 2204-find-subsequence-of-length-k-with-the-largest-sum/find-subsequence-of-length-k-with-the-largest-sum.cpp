class Solution {
public:
    static bool cmp(pair<int,int>& a, pair<int,int>& b) {
        return a.first>b.first;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end(),cmp);
        vector<pair<int,int>>v1(v.begin(),v.begin()+k);
        sort(v1.begin(),v1.end(), [](pair<int,int>& a, pair<int,int>& b){
            return a.second < b.second;
        });
        vector<int>ans;
        for(auto it:v1){
            ans.push_back(it.first);
        }
        return ans;
    }
};