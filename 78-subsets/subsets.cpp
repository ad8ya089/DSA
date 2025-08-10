class Solution {
public:
    //Backtracking
    int n;
    void backtrack(int start,vector<vector<int>>&list,vector<int>tempList,vector<int>& nums){
        list.push_back(tempList);
        for(int i=start;i<n;i++){
            tempList.push_back(nums[i]); 
            backtrack(i+1,list,tempList,nums);
            tempList.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(0,list,tempList,nums);
        return list;
    }
};