class Solution {
public:
    int totProducts(vector<int>&arr,int products){
        int n=arr.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=arr[i]/products;
            if(arr[i]%products!=0) sum++;
        }
        return sum;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1,r=*max_element(quantities.begin(),quantities.end()); //dekha yaha max element ko hi r liya kyuki integer hai aur max se zyada lega toh sb divide hoke 0 return krenge
        int ans=1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(totProducts(quantities,mid)<=n){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};