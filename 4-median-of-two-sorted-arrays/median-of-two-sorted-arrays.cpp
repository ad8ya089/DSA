class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        if(m>n) return findMedianSortedArrays(nums2,nums1); //brilliant method
        int low=0,high=m;
        int reqLeft=(n+m+1)/2;
        while(low<=high){
            int mid1=(low+high)>>1;
            int mid2=reqLeft-mid1;
            int l1=INT_MIN,l2=INT_MIN;
            int r1=INT_MAX,r2=INT_MAX;
            if(mid1-1>=0) l1=nums1[mid1-1];
            if(mid2-1>=0) l2=nums2[mid2-1];
            if(mid1<m) r1=nums1[mid1];
            if(mid2<n) r2=nums2[mid2];
            if(l1>r2){
                high=mid1-1;
            }
            else if(l2>r1){
                low=mid1+1;
            }
            else{
                double ele1=max(l1,l2);
                double ele2=min(r1,r2);
                if((m+n)%2==0){ 
                    return (ele1+ele2)/2.0;
                }
                else{
                    return ele1;
                }
            }
        }
        return 0;
    }
};