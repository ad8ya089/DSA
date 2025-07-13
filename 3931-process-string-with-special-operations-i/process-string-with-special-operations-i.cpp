class Solution {
public:
    string processStr(string s) {
        int n=s.size();
        string ans="";
        for(char c:s){
            if(c=='*'){
                if(ans.size()!=0) ans.pop_back();
            }
            else if(c=='#'){
                string str=ans;
                ans+=str;
            }
            else if(c=='%'){
                reverse(ans.begin(),ans.end());
            }
            else{
                ans+=c;
            }
        }
        return ans;
    }
};