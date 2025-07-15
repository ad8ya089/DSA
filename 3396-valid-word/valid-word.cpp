class Solution {
public:
    bool isValid(string word) {
        int n=word.size();
        if(n<3) return false;
        int ct=0,ct1=0;
        for(char ch:word){
            if((ch<'0' or ch>'9') and (ch<'a' or ch>'z') and (ch<'A' or ch>'Z')){
                return false;
            }
            if(ch=='a' or ch=='e' or ch=='i' or ch=='o' or ch=='u' or ch=='A' or ch=='E' or ch=='I' or ch=='O' or ch=='U') ct++;
            else{
                if(ch>'9') ct1++;
            }
        }
        if(ct==0 or ct1==0) return false; 
        return true;
    }
};