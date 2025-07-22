class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        unordered_map<int,int>mp;
        int sum=0,mx=0;
        while(r<n){
            while(mp[nums[r]]!=0){
                sum-=nums[l];
                mp[nums[l]]--;
                l++;
            }
            sum+=nums[r];
            mx=max(sum,mx);
            mp[nums[r]]++;
            r++;
        }
        return mx;
    }
};