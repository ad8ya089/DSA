class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //Method 2 (max,min DP)
        int currMX=1,currMN=1; //constraints dekho
        int ans=*max_element(nums.begin(),nums.end());
        for(int ele:nums){
            int temp=currMX*ele;
            currMX=max({ele,ele*currMX,ele*currMN});
            currMN=min({ele,temp,ele*currMN});
            ans=max(ans,currMX);
        }
        return ans;
    }
};