class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>a(n);
        int ind=1;
        if(n%2==0) ind=0;
        for(int i=ind;i<n;i+=2){
            a[i]=0-1000-i;
            a[i+1]=0+1000+i;
        }
        if(n%2!=0) a[0]=0;
        return a;
    }
};