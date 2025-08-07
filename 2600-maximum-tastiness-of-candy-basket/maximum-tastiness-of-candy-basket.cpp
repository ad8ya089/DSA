class Solution {
public:
    bool possible(vector<int>& price, int k,int diff){
        int n=price.size();
        int prev=price[0];
        int ct=1;
        for(int i=1;i<n;i++){
            if(price[i]-prev>=diff){
                prev=price[i];
                ct++;
            }
            if(ct==k) return true;
        }
        return false;
    }
    int maximumTastiness(vector<int>& price, int k) {
        int n=price.size();
        sort(price.begin(),price.end());
        int mx=*max_element(price.begin(),price.end());
        int mn=*min_element(price.begin(),price.end());
        int l=0,r=mx-mn,ans=0;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(possible(price,k,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};