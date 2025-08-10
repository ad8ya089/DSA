class Solution {
public:
    //Backtracking with space
    int n;
    void backtrack(int ind,vector<vector<int>>&list,vector<int>&tempList,vector<int>& nums,vector<bool>&used){
        if(tempList.size()==n){
            list.push_back(tempList);
            return;
        }
        for(int i=0;i<n;i++){
            if(used[i] or (i>0 and nums[i]==nums[i-1] and !used[i-1])) continue; //duplicate h toh ma chuda
            used[i]=1;
            tempList.push_back(nums[i]);
            backtrack(i+1,list,tempList,nums,used);
            used[i]=0;
            tempList.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>list;
        vector<int>tempList;
        vector<bool>used(n,false);
        backtrack(0,list,tempList,nums,used);
        return list;
    }
};