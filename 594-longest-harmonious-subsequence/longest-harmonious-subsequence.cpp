class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int l=0,r=1,mx=0;
        while(r<n){
            if(nums[r]-nums[l]==1){
                mx=max(mx,r-l+1);
                r++;
            }
            else if(nums[r]-nums[l]==0) r++;
            else{
                l++;
            }
        }
        return mx;
    }
};