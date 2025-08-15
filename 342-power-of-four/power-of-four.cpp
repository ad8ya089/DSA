class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        int ct=0;
        while(n%2==0){
            ct++;
            n/=2;
        }
        if(n!=1) return false;
        return (ct%2==0) ? true : false;
    }
};