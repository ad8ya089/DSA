class Solution {
public:
    //Tabulation with space optimisation (2 arrays)
    int longestCommonSubsequence(string s1, string s2) {
        int n1=s1.size(),n2=s2.size();
        vector<int>prev(n2+1,0),curr(n2+1,0); 
        //n1+1,n2+1 liye instead of n1,n2 to incorporate base case of negative indices, smjha mc
        //1-based indexing krdiye hai so string ka index uss hisab se ek-ek kam krdena
        for(int ind1=1;ind1<=n1;ind1++){
            for(int ind2=1;ind2<=n2;ind2++){
                if(s1[ind1-1]==s2[ind2-1]) curr[ind2]=1+prev[ind2-1]; //Match
                else curr[ind2]=0+max(prev[ind2],curr[ind2-1]); //Not matching
            }
            prev=curr;
        }
        return prev[n2];
    }
};