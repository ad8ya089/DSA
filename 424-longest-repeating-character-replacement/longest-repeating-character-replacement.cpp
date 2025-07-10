class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        vector<int>v(26);
        int l=0,r=0,ans=0,mx=0;
        while(r<n){
            v[s[r]-'A']++;
            mx=max(mx,v[s[r]-'A']);
            int other=(r-l+1)-mx;
            while(other>k){
                other--;
                v[s[l]-'A']--;
                l++;
            }
            if(other<=k){
                ans=max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};