class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int zero=0,one=0,l=0,r=0,mx=0;
        while(r<n){
            if(nums[r]==0) zero++;
            while(zero>k){
                if(nums[l]==0) zero--;
                l++;
            }
            if(zero<=k){
                mx=max(mx,r-l+1);
                r++;
            }
        }
        return mx;
    }
};