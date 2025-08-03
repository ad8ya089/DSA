class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i+1<n and nums[i]<nums[i+1]) i++;
        if(i==0 or i==n-1) return false;
        int p=i;
        while(i+1<n and nums[i]>nums[i+1]) i++;
        if(i==p or i==n-1) return false;
        int q=i;
        while(i+1<n and nums[i]<nums[i+1]) i++;
        if(i!=n-1) return false;
        return true;
    }
};