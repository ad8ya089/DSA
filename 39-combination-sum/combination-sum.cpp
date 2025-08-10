class Solution {
public:
    //Aryan's backtracking template (iske pehle wala submission was take/notTake recursion)
    int n;
    void backtrack(int start,vector<int>&candidates,int target,vector<vector<int>>&list,vector<int>&tempList){
        if(target<0) return;
        else if(target==0) list.push_back(tempList);
        else{
            for(int i=start;i<n;i++){
                tempList.push_back(candidates[i]);
                backtrack(i,candidates,target-candidates[i],list,tempList);
                tempList.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n=candidates.size();
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(0,candidates,target,list,tempList);
        return list;
    }
};