class Solution {
public:
    int maxConsecutiveAnswers(string key, int k) {
        int n=key.size();
        int f=0,t=0;
        int l=0,r=0,mx=0;
        while(r<n){
            if(key[r]=='F') f++;
            else t++;
            while(l<=r and min(f,t)>k){
                if(key[l]=='F') f--;
                else{
                    t--;
                }
                l++;
            }
            mx=max(mx,r-l+1);
            r++;
        }
        return mx;
    }
};