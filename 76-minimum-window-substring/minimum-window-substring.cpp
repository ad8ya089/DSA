class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        vector<int>hash(128);
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        int l=0,r=0,cnt=0,mn=INT_MAX,sind;
        while(r<n){
            if(hash[s[r]]>0){
                cnt++;
            }
            hash[s[r]]--;
            //valid substring --> ab chhota kr jitna ho sake
            while(cnt==m and l<n){
                if(r-l+1<mn){
                    sind=l;
                    mn=r-l+1;
                }
                if(hash[s[l]]<=0){
                    hash[s[l]]++;
                }
                if(hash[s[l]]>0) cnt--; //koi ek t ka character s ke substring mei kam hogya
                l++;
            }
            r++;
        }
        if(mn==INT_MAX) return "";
        string str="";
        for(int i=sind;i<sind+mn;i++){
            str+=s[i];
        }
        return str;
    }
};