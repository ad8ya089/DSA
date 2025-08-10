class Solution {
public:
    //Backtracking using space(visited array)
    int n;
    void backtrack(int start,vector<vector<int>>&list,vector<int>&tempList,vector<int>&nums,vector<bool>&used)
    {
        if(tempList.size()==n){
            list.push_back(tempList);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i]) continue;
            used[i]=true;
            tempList.push_back(nums[i]);
            backtrack(i+1,list,tempList,nums,used);
            used[i]=false;
            tempList.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>list;
        vector<int>tempList;
        vector<bool>used(n,false);
        backtrack(0,list,tempList,nums,used);
        return list;
    }
};