class Solution {
public:
    int maximumLength(string s) {
        int n=s.size();
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++){
            string str="";
            char c=s[i];
            bool f=1;
            for(int j=i;j<n;j++){
                str+=s[i];
                if(c==s[j] and f) mp[str]++;
                else f=0;
            }
        }
        int mx=-1;
        for(auto &it:mp){
            // cout<<it.first<<" "<<it.second<<endl;
            if(it.second>=3){
                string str=it.first;
                int n1=str.size();
                mx=max(mx,n1);
            }
        }
        return mx;
    }
};