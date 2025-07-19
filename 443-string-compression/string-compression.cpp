class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ct=1;
        string s="";
        s+=chars[0];
        for(int i=1;i<n;i++){
            if(chars[i]==chars[i-1]){
                ct++;
                continue;
            }
            if(ct==1) s+=chars[i];
            else{
                string k=to_string(ct);
                s+=k;
                s+=chars[i];
                ct=1;
            }
        }
        if(ct!=1){
            string k=to_string(ct);
            s+=k;
        }
        for(int i=0;i<s.size();i++){
            chars[i]=s[i];
        }
        return s.size();
    }
};