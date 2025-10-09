class Solution {
public:
    const int N=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.size();
        vector<vector<int>>dp(26,vector<int>(t+1,0));
        //kinda precomputation
        for(int c=0;c<26;c++){
            dp[c][0]=1; //jo hai so hai
        }
        for(int steps=1;steps<=t;steps++){
            for(int ch=0;ch<25;ch++){
                dp[ch][steps]=dp[ch+1][steps-1];
            }
            dp[25][steps]=(dp[0][steps-1]+dp[1][steps-1])%N; //z ko ab banado
        }
        int ans=0;
        for(char ch:s){
            ans=(ans+dp[ch-'a'][t])%N;
        }
        return ans;
    }
};