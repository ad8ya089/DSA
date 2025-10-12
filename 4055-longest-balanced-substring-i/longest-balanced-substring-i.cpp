class Solution {
public:
    bool equal(vector<int>&freq){
        int mn=INT_MAX,mx=INT_MIN;
        for(int f:freq){
            if(f==0) continue;
            mn=min(mn,f);
            mx=max(mx,f);
        }
        return mn==mx;
    }
    int longestBalanced(string s) {
        int n=s.size();
        int mx=0;
        for(int i=0;i<n;i++){
            vector<int>freq(26);
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                if(equal(freq)){
                    mx=max(mx,j-i+1);
                }
            }

        }
        return mx;
    }
};