class Solution {
public:
    //Langrange's 4 square theorem 
    //Adrien-Marie Legendre 3-square theorem 
    int numSquares(int n) {
        int val=sqrt(n);
        if(val*val==n) return 1; //n khud hi perfect square hai
        while(n%4==0){ //4^k(8m+7) ke form mei hoga tbhi 4 honge integer squares
            n/=4;
        }
        if(n%8==7) return 4;
        // n ko saare 4 se divide krke 3 squares hone ka possibility khtm ni kr dete just that scale jo horha tha 2^2 se har integer square toh voh hat gya and ab sb integers jiske squares se ban rha hai voh aapas mei 2 GCD ni rkhte hai, like 324=4*81 , toh 324 aur 81 dono hi square toh rhenge hi naa irrespective of 4 hataye ya ni 
        for(int i=1;i*i<=n;i++){ //sum of 2 perfect squares hai ya ni
            int sq=i*i;
            int rem=(int)sqrt(n-sq);
            if(rem*rem==n-sq){
                return 2;
            }
        }
        return 3;
    }
};