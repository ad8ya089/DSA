class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int k=0;
        for(int i=0;i<n;i++){
            if(nums[i]==1) k++;
        }
        int zero=0;
        //first k window
        for(int i=0;i<k;i++){
            if(nums[i]==0) zero++;
        }
        int ans=zero;
        //further k windows
        for(int i=k;i<n;i++){
            if(nums[i-k]==0) zero--;
            if(nums[i]==0) zero++;
            ans=min(ans,zero);
        }
        //circular array k window
        for(int i=n;i<n+k;i++){
            if(nums[i-k]==0) zero--;
            if(nums[i%n]==0) zero++;
            ans=min(ans,zero);
        }
        return ans;
    }
};