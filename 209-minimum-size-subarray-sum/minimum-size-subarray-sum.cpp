class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int sum=0,mn=INT_MAX;
        while(r<n){
            sum+=nums[r];
            r++;
            while(sum>=target){
                mn=min(mn,r-l);
                sum-=nums[l];
                l++;
            }
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};