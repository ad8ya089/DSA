class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int i=0,j=0;
        int cnt=0;
        int n1=m+n;
        int ind2=n1/2;
        int ind1=ind2-1;
        int ele1=-1,ele2=-1;
        while(i<m and j<n){
            if(nums1[i]<nums2[j]){
                if(cnt==ind1) ele1=nums1[i];
                if(cnt==ind2) ele2=nums1[i];
                i++;
            }
            else{
                if(cnt==ind1) ele1=nums2[j];
                if(cnt==ind2) ele2=nums2[j];
                j++;
            }
            cnt++;
        }
        while(i<m){ //if j exhausts
            if(cnt==ind1) ele1=nums1[i];
            if(cnt==ind2) ele2=nums1[i];
            i++;
            cnt++;
        }
        while(j<n){ //if i exhausts
            if(cnt==ind1) ele1=nums2[j];
            if(cnt==ind2) ele2=nums2[j];
            j++;
            cnt++;
        }
        if(n1%2!=0){
            return (double)ele2;
        }
        else{
            double sum=ele1+ele2;
            return sum/2.000000;
        }
        return 0;
    }
};