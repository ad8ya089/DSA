class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n<=0) return 0;
        int k=n&(n-1);
        return k==0;
    }
};