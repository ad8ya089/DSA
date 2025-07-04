class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k){
            int n=s.size();
            for(int i=0;i<n;i++){
                int val=s[i]-'a';
                char ch=(char)('a'+val+1);
                s.push_back(ch);
            }
        }
        return s[k-1];
    }
};