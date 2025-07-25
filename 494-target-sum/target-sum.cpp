class Solution {
public:
    //Memoization
    //count ways hai toh 0/1 hi return krna h base case mei
    int f(int ind,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==0){
            if(target-nums[0]==0 and target+nums[0]==0) return 2;
            if(target-nums[0]==0 or target+nums[0]==0) return 1;
            return 0;
        }
        if(target+1000<0 or target+1000>=2001) return 0;
        if(dp[ind][target+1000]!=-1) return dp[ind][target+1000];
        int add=f(ind-1,target-nums[ind],nums,dp);
        int sub=f(ind-1,target+nums[ind],nums,dp);
        return dp[ind][target+1000]=add+sub; 
    }
    int findTargetSumWays(vector<int>& nums, int amount) {
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(2001,-1));
        return f(n-1,amount,nums,dp);
    }
};