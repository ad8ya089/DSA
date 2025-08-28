class Solution {
public:
    //Tabulation (Bottom-Up) --> O(n^2)
    bool predictTheWinner(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            dp[i][i]=nums[i];
        }
        for(int len=2;len<=n;len++){
            for(int left=0;left+len-1<n;left++){
                int right=left+len-1;
                int scoreL=nums[left]-dp[left+1][right];
                int scoreR=nums[right]-dp[left][right-1];
                dp[left][right]=max(scoreL,scoreR);
            }
        }
        return dp[0][n-1]>=0;
    }
};