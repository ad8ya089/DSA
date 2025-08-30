class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        int ind=0,prev=0;
        for(int i=0;i<n-1;i++){
            if(chars[i]!=chars[i+1]){
                int length=i-prev+1;
                chars[ind++]=chars[i];
                if(length>1){
                    string s=to_string(length);
                    for(int j=0;j<(int)s.size();j++){
                        chars[ind++]=s[j]; 
                    }
                }
                prev=i+1;
            }
        }
        int length=n-prev;
        chars[ind++]=chars[n-1];
        if(length>1){
            string s=to_string(length);
            for(char c:s) chars[ind++]=c;
        }
        return ind;
    }
};