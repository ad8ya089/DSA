class Solution {
public:
    int MOD=1e9+7;
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>pow2(n+1,1);
        for(int i=1;i<=n;i++){
            pow2[i]=(pow2[i-1]*2LL)%MOD;
        }
        int l=0,r=n-1;
        int ans=0;
        while(l<=r){
            if(nums[l]+nums[r]>target){
                r--;
            }
            else{
                ans=(ans+pow2[r-l]%MOD)%MOD;
                l++;
            }
        }
        return ans;
    }
};