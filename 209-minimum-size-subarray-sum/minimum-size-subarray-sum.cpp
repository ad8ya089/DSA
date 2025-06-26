class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int sum=0,mn=INT_MAX;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                mn=min(mn,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        if(mn==INT_MAX) return 0;
        return mn;
    }
};