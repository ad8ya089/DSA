class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        //Space optimisation using 1 array and 1 variable (kyuki ek hi element of prev array pe depend kr rha tha jisko hum variable mei hi store krliye)
        int n1=s1.size(),n2=s2.size();
        vector<int>curr(n2+1,0);
        int prev=0;
        //n1+1,n2+1 liye instead of n1,n2 to incorporate base case of negative indices, smjha mc
        //1-based indexing krdiye hai so string ka index uss hisab se ek-ek kam krdena
        for(int i=1;i<=n1;i++){
            prev=0;
            for(int j=1;j<=n2;j++){
                int prev1=curr[j];
                if(s1[i-1]==s2[j-1]) curr[j]=1+prev;//Match
                else curr[j]=0+max(curr[j],curr[j-1]); //Not Match
                prev=prev1;
            }
        }
        return curr[n2];
    }
};