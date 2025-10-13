class Solution {
public:
    bool ana(string s,string t){
        int n=s.size(),m=t.size();
        if(m!=n) return 0;
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        return s==t;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n=words.size();
        vector<bool>vis(n);
        bool f=1;
        for(int i=1;i<n;i++){
            if(ana(words[i],words[i-1])){
                vis[i]=1;
            }
        }
        vector<string>ans;
        for(int i=0;i<n;i++){
            if(!vis[i]) ans.push_back(words[i]);
        }
        return ans;
    }
};