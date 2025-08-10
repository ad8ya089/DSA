class Solution {
public:
    //Backtracking without space
    int n;
    void backtrack(int start,vector<vector<int>>&list,vector<int>&nums)
    {
        //start uss pointer pe hai jaha pe hum uske baad ke saare elements laa skte hai to create a permutation
        if(start==n){
            list.push_back(nums);
            return;
        }
        for(int i=start;i<n;i++){
            swap(nums[i],nums[start]); //swap 1->1, 1->2, 1->3, vaise hi 2->2,2->3 and 3->3
            backtrack(start+1,list,nums); //pointer ko aage badhao na ki index ko
            swap(nums[i],nums[start]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>list;
        backtrack(0,list,nums);
        return list;
    }
};