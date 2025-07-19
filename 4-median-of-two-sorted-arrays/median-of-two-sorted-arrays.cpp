class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        if(n1>n2) return findMedianSortedArrays(nums2,nums1);
        int reqLeft=(n1+n2+1)/2; //even hoga toh equal elements dono taraf, odd hua toh zyada wala left taraf hoga
        int l=0,r=n1; //sbse kam ya toh 0 le skte nums1 ka ya toh pura le skte
        double ele1=0,ele2=0;
        while(l<=r){
            int mid1=(l+r)>>1;
            int mid2=reqLeft-mid1;
            int l1=INT_MIN,l2=INT_MIN; //inka max lena hoga na
            int r1=INT_MAX,r2=INT_MAX; //inka min lena hoga median k liye
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(mid1<n1) r1=nums1[mid1];
            if(mid2<n2) r2=nums2[mid2];
            if(l1>r2){
                r=mid1-1;
            }
            else if(l2>r1){
                l=mid1+1;
            }
            else{
                ele1=max(l1,l2);
                ele2=min(r1,r2);
                break;
            }
        } 
        int tot=n1+n2;
        if(tot%2==0){
            return (double)(ele1+ele2)/2.0;
        }
        else{
            return ele1;
        }
    }
};