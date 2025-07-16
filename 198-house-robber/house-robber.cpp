class Solution {
public:
    //Tabulation(Bottom-Up Approach) with space optimisation
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev2=0,prev1=nums[0];
        for(int ind=1;ind<n;ind++){
            int take=nums[ind];
            if(ind>1) take+=prev2;
            int notTake=0+prev1;
            int curr_i=max(take,notTake);
            prev2=prev1;
            prev1=curr_i;
        }
        return prev1;
    }
};