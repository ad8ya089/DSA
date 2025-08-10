class Solution {
public:
    //Aryan's backtracking template (iske pehle wala submission was take/notTake recursion)
    int n;
    void backtrack(int start,vector<int>&candidates,int target,vector<vector<int>>&list,vector<int>&tempList){
        if(target<0) return;
        else if(target==0) list.push_back(tempList);
        else{
            for(int i=start;i<n;i++){
                if(i>start and candidates[i]==candidates[i-1]) continue;
                tempList.push_back(candidates[i]);
                backtrack(i+1,candidates,target-candidates[i],list,tempList); //aage bdho 
                tempList.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>list;
        vector<int>tempList;
        backtrack(0,candidates,target,list,tempList);
        return list;
    }
};