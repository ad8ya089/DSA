class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long l=0,r=0,sum=0,mx=0;
        while(r<n){
            sum+=nums[r];
            while(l<r and  (r-l+1)*nums[r]-sum>k){
                sum-=nums[l];
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};