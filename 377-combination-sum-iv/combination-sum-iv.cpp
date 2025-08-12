class Solution {
public:
    //Memo
    vector<int>dp;
    int n;
    int f(int target,vector<int>&nums){
        if(target==0) return 1; 
        if(target<0) return 0;
        if(dp[target]!=-1) return dp[target];
        int ways=0;
        for(int n:nums){
            ways+=f(target-n,nums);
        }
        return dp[target]=ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        dp=vector<int>(target+1,-1);
        return f(target,nums);
    }
};