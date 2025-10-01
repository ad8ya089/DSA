class Solution {
public:
    long long splitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>pref(n);
        vector<long long>suff(n);
        pref[0]=nums[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+nums[i];
        }
        suff[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i]=suff[i+1]+nums[i];
        }
        
        vector<bool>inc(n,0),dec(n,0);
        inc[0]=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1] and inc[i-1]) inc[i]=1;
        }
        dec[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>nums[i+1] and dec[i+1]) dec[i]=1;
        }
        long long mn=LLONG_MAX;
        for(int i=0;i<n-1;i++){
            if(inc[i] and dec[i+1]){
                long long diff=llabs(pref[i]-suff[i+1]);
                mn=min(mn,diff);
            }
        }
        return (mn==LLONG_MAX) ? -1 : mn;
    }
};