class Solution {
public:
    int n;
    //Memo
    int f(int num,vector<int>&freq,vector<int>&dp){
        if(num<0){
            return 0;
        }
        if(dp[num]!=-1) return dp[num];
        int notDlt=f(num-1,freq,dp);
        int dlt=freq[num]+f(num-2,freq,dp); //num+1 toh aise bhi ni jaega
        return dp[num]=max(dlt,notDlt);
    }
    int deleteAndEarn(vector<int>& nums) {
        n=nums.size();
        int mx=*max_element(nums.begin(),nums.end());
        vector<int>freq(mx+1,0),dp(mx+1,-1);
        for(int i=0;i<n;i++){
            freq[nums[i]]+=nums[i];
        }
        return f(mx,freq,dp);
    }
};