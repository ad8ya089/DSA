class Solution {
public:
    int n;
    void backtrack(int ind,vector<int>&candidates,int target,vector<vector<int>>&list,vector<int>&tempList){
        if(target<0) return;
        if(ind==n){
            if(target==0){
                list.push_back(tempList);
            }
            return;
        }
        //take (vhi reh kyuki ek ko kitni baar bhi le skte)
        tempList.push_back(candidates[ind]);
        backtrack(ind,candidates,target-candidates[ind],list,tempList);
        //notTake (aage badh jaye bina liye)
        tempList.pop_back();
        backtrack(ind+1,candidates,target,list,tempList);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(0,candidates,target,list,tempList);
        return list;
    }
};