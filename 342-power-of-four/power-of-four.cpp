class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<=0) return false;
        //Power of 2 and divisibility by 3 (proved)
        if((n&(n-1))==0 and (n-1)%3==0) return true;
        return false;
    }
};