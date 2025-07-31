class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int x:nums){
            mp[x]++;
        }
        for(int x:nums){
            if(mp[x]==1){
                if(mp.find(x-1)==mp.end() and mp.find(x+1)==mp.end()){
                    ans.push_back(x);
                }
            }
        }
        return ans;
    }
};