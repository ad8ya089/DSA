class Solution {
public:
    int maxAdjSum(vector<int>&nums){
        //Tabulation with space optimisation
        int n=nums.size();
        int prev=nums[0],prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i]; 
            if(i>1) take+=prev2; //Negative values avoid kr rhe
            int notTake=0+prev;
            int curri=max(take,notTake);
            prev2=prev;prev=curri;
        }    
        return prev;
    }
    int rob(vector<int>& nums) {
        vector<int> temp1,temp2;
        int n=nums.size();
        if(n==1) return nums[0]; 
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        int ans1=maxAdjSum(temp1);
        int ans2=maxAdjSum(temp2);
        return max(ans1,ans2);
    }
};