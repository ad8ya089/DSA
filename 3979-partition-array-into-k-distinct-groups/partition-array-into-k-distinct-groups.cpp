class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k) return false;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]]++;
        }
        int mx=n/k;
        for(auto it:mp){
            if(it.second>mx) return false;
        }
        return true;
    }
};