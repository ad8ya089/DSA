class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ct=0,mx=0;
        for(int r=2;r<n;r++){
            if((nums[r-2]+nums[r-1])!=nums[r]){
                mx=max(mx,ct);
                ct=0;
                continue;
            }
            ct++;
        }
        mx=max(mx,ct);
        return mx+2;
    }
};