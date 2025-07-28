class Solution {
public:
    //Memoization
    int n;
    int f(int ind,int currOR,int target,vector<int>& nums,vector<vector<int>>&dp){
        if(ind==n){
            if(currOR==target) return 1;
            return 0;
        }
        if(dp[ind][currOR]!=-1) return dp[ind][currOR];
        int take=f(ind+1,currOR|nums[ind],target,nums,dp);
        int notTake=f(ind+1,currOR,target,nums,dp);
        return dp[ind][currOR]=take+notTake;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n=nums.size();
        int mxOR=0;
        for(int x:nums){
            mxOR|=x;
        }
        vector<vector<int>>dp(n,vector<int>(mxOR+1,-1));
        return f(0,0,mxOR,nums,dp);
    }
};