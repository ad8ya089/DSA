class Solution {
public:
    int countPartitions(vector<int>&nums,int reqSum){
        int n=nums.size();
        long long sum=nums[0];
        int cnt=1;
        for(int i=1;i<n;i++){
            if(sum+nums[i]>reqSum){
                cnt++;
                sum=nums[i];
                continue;
            }
            sum+=nums[i];
        }
        return cnt;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=l;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(countPartitions(nums,mid)<=k){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }   
        return l; //kyuki r possible parity pe h initially as we are finding the minimum of max
    }
};