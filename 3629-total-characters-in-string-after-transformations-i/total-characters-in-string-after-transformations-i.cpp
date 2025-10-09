class Solution {
public:
    const int N=1e9+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.size();
        vector<vector<int>>dp(26,vector<int>(t+1,0));
        //dp[c][k]-->no. of characters jo generate hoskte agar c se start kre and k baari transform kre
        //kinda precomputation
        for(int c=0;c<26;c++){
            dp[c][0]=1; //0 mei toh same hi rhega na
        }
        for(int steps=1;steps<=t;steps++){
            for(int ch=0;ch<25;ch++){
                dp[ch][steps]=dp[ch+1][steps-1]; //maano a se start kre s step leke toh b se start krne ko ek step kam lgenge na toh dp[a][steps]=dp[b][steps-1]
                //isko memo se krte toh ans=f(ch+1,steps-1) se krte zyada ache visualise hota
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