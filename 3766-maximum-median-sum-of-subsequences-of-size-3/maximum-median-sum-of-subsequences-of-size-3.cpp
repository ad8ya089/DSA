class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=n-2;
        int k=n/3;
        long long ans=0;
        while(k--){
            ans+=nums[i];
            i-=2;
        }
        return ans;
    }
};