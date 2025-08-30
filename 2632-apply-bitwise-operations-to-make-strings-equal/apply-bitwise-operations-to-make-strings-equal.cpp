class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int n1=s.size(),n2=target.size();
        if(n1!=n2) return false;
        int zero1=0,zero2=0;
        for(int i=0;i<n1;i++){
            if(s[i]=='0') zero1++;
            if(target[i]=='0') zero2++;
        }
        if(s==target) return true;
        if(zero1==n1 or zero2==n1) return false; 
        return true;
    }
};