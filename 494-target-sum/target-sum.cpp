class Solution {
public:
    //Tabulation
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        //s1-s2==d => sum-2s2=d => s2=(sum-d)/2 -->yehi count krna h
        int n=arr.size();
        int sum=accumulate(arr.begin(),arr.end(),0);
        int s=(sum-d)/2;
        if((sum-d)%2 or (sum-d)<0) return 0;
        vector<vector<int>>dp(n,vector<int>(s+1,0));
        if (arr[0] == 0) dp[0][0] = 2;  // pick or not pick
        else dp[0][0] = 1;
        if (arr[0] != 0 && arr[0] <= s)
            dp[0][arr[0]] = 1;
        for(int ind=1;ind<n;ind++){
            for(int target=0;target<=s;target++){
                int pick=0;
                if(target>=arr[ind]) pick=dp[ind-1][target-arr[ind]];
                int notPick=dp[ind-1][target];
                dp[ind][target]=pick + notPick;
            }
        }
        return dp[n-1][s];
    }
    //basically ismei bhi toh vhi krna hai, count number of subsets jisse do bhaag mei baat ke ek ko plus krke aur ek ko minus krke target amount mil jaaye
    int findTargetSumWays(vector<int>& nums, int amount) {
        return countPartitions(nums,amount);
    }
};