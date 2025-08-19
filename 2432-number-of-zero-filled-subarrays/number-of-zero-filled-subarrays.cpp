class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        vector<int>v;
        int n=nums.size(),ct=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                if(ct!=0){
                    v.push_back(ct);
                    ct=0;
                }
                continue;
            }
            ct++;
        }
        if(ct!=0){
            v.push_back(ct);
        }
        long long ans=0;
        for(int i=0;i<v.size();i++){
            int cnt=v[i];
            ans+=(1LL*cnt*(cnt+1))/2;
        }
        return ans;
    }
};