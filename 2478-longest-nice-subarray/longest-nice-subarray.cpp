class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int xr=0,mx=0,sum=0;
        while(r<n){
            xr^=nums[r];
            sum+=nums[r];
            while(l<r and xr!=sum){
                xr^=nums[l];
                sum-=nums[l];
                l++;
            }
            mx=max(mx,r-l+1);
            r++; 
        }
        return mx;
    }
};