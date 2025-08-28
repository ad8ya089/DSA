class Solution {
public:
    //Basic recursion --> Brute force --> O(2^n)
    int n;
    int maxDiff(vector<int>&nums,int left,int right){
        if(left==right){
            return nums[left];
        }
        int scoreL=nums[left]-maxDiff(nums,left+1,right);
        int scoreR=nums[right]-maxDiff(nums,left,right-1);
        return max(scoreL,scoreR);
    }
    bool predictTheWinner(vector<int>& nums) {
        n=nums.size();
        int mxD=maxDiff(nums,0,n-1);
        return mxD>=0;
    }
};