class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        double pre=1,suff=1;
        int n=nums.size();
        int start=0,end=0,mx=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                pre=1;
                start=i+1;
                continue;
            }
            pre*=nums[i];
            if(pre>0) mx=max(mx,i-start+1);
        }
        end=n-1;
        for(int i=n-1;i>=0;i--){
            if(nums[i]==0){
                suff=1;
                end=i-1;
                continue;
            }
            suff*=nums[i];
            if(suff>0) mx=max(mx,end-i+1);
        }
        return mx;
    }
};