class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        vector<char>v(256);
        int r=0,l=0,mx=0;;
        while(r<n){
            while(v[s[r]]!=0){
                v[s[l]]--;
                l++;
            }
            if(v[s[r]]==0){
                mx=max(mx,r-l+1);
                v[s[r]]++;
            }
            r++;
        }
        return mx;
    }
};