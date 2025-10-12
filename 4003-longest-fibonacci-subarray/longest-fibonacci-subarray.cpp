class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        vector<bool>v(n-2);
        for(int i=2;i<n;i++){
            v[i]=((nums[i]-nums[i-1]-nums[i-2])==0);
        }
        int ct=0,mx=0;
        for(int r=0;r<n;r++){
            if(!v[r]){
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