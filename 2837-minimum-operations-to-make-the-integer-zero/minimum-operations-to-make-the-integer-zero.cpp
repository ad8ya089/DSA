class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
            long long s=num1-1LL*k*num2;
            if(s<0) continue;
            if(__builtin_popcountll(s)<=k and k<=s){ // no. of set bits<=k
                return k;
            }
        }
        return -1;
    }
};