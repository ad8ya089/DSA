class Solution {
public:
    string compressedString(string word) {
        int n=word.size();
        int prev=0;
        string ans="";
        if(n==1) return ans+'1'+word[0];
        for(int i=1;i<n;i++){
            if(word[i]!=word[i-1]){
                int len=i-prev;
                while(len>9){
                    ans+='9';
                    ans+=word[i-1];
                    len-=9;
                }
                char ct=len+'0';
                ans+=ct;
                ans+=word[i-1];
                prev=i;
            }
        }
        if(word[n-1]!=word[n-2]){
            ans+='1';
            ans+=word[n-1];
        }
        else{
            int len=n-prev; //(n-1)-prev+1 -->kyuki iss baar toh n-1 khud included 
            while(len>9){
                ans+='9';
                ans+=word[n-1];
                len-=9;
            }
            char ct=len+'0';
            ans+=ct;
            ans+=word[n-1];
        }
        return ans;
    }
};