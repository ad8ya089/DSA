class Solution {
public:
    //Bit manipulation
    int countMaxOrSubsets(vector<int>& nums) {
        int n=nums.size();
        int mx=0;
        vector<int>dp(1<<17,0);
        //empty subset ka xor 0 hoga
        dp[0]=1;
        for(int num:nums){
            for(int i=mx;i>=0;i--){
                dp[i|num]+=dp[i];
            }
            mx|=num;
        }
        return dp[mx];
    }
};