class Solution {
public:
    int lcp(string a,string b){
        int n=min(a.size(),b.size());
        int ct=0;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]) break;
            ct++;
        }
        return ct;
    }
    vector<int> longestCommonPrefix(vector<string>& s) {
        int n=s.size();
        vector<int>ans(n);
        if(n<=2) return ans;
        vector<int>lcps;
        for(int i=1;i<n;i++){
            lcps.push_back(lcp(s[i],s[i-1]));
        }
        vector<int>pre(n);
        vector<int>suff(n);
        for(int i=1;i<n;i++){
            pre[i]=max(pre[i-1],lcps[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suff[i]=max(suff[i+1],lcps[i]);
        }
        ans[0]=suff[1];
        for(int i=1;i<n-1;i++){
            ans[i]=max({pre[i-1],suff[i+1],lcp(s[i-1],s[i+1])});
        }
        ans[n-1]=pre[n-2];
        return ans;
    }
};